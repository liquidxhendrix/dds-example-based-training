/*
* (c) Copyright, Real-Time Innovations, 2020.  All rights reserved.
* RTI grants Licensee a license to use, modify, compile, and create derivative
* works of the software solely for use with RTI Connext DDS. Licensee may
* redistribute copies of the software provided that all such copies are subject
* to this license. The software is provided "as is", with no warranty of any
* type, including any warranty for fitness for any purpose. RTI is under no
* obligation to maintain or support the software. RTI shall not be liable for
* any incidental or consequential damages arising out of the use or inability
* to use the software.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "car_basic_info.h"
#include "car_basic_infoSupport.h"
#include "ndds/ndds_cpp.h"
#include "application.h"

using namespace application;

static int shutdown_participant(
    DDSDomainParticipant *participant,
    const char *shutdown_message,
    int status);

class ReaderListener : public DDSDataReaderListener {
public:
    virtual void on_requested_deadline_missed(
            DDSDataReader * /*reader*/,
            const DDS_RequestedDeadlineMissedStatus & /*status*/)
    {
        printf("ReaderListener: on_requested_deadline_missed()\n");
    }

    virtual void on_requested_incompatible_qos(
            DDSDataReader * /*reader*/,
            const DDS_RequestedIncompatibleQosStatus & /*status*/)
    {
        printf("ReaderListener: on_requested_incompatible_qos()\n");
    }

    virtual void on_sample_rejected(
            DDSDataReader * /*reader*/,
            const DDS_SampleRejectedStatus & /*status*/)
    {
        printf("ReaderListener: on_sample_rejected()\n");
    }

    virtual void on_liveliness_changed(
            DDSDataReader * /*reader*/,
            const DDS_LivelinessChangedStatus &status)
    {
        printf("ReaderListener: on_liveliness_changed()  -- FROM ZHIKAI\n");
        printf("  Alive writers: %d\n", status.alive_count);
    }

    virtual void on_sample_lost(
            DDSDataReader * /*reader*/,
            const DDS_SampleLostStatus & /*status*/)
    {
        printf("ReaderListener: on_sample_lost()\n");
    }

    virtual void on_subscription_matched(
            DDSDataReader * /*reader*/,
            const DDS_SubscriptionMatchedStatus & /*status*/)
    {
        printf("ReaderListener: on_subscription_matched() -- FROM ZHIKAI\n");
    }

    virtual void on_data_available(DDSDataReader *reader);
};

void ReaderListener::on_data_available(DDSDataReader *reader)
{
    carBasicInfoDataReader *listeners_reader = NULL;
    carBasicInfoSeq data_seq;     // Sequence of received data
    DDS_SampleInfoSeq info_seq; // Metadata associated with samples in data_seq
    DDS_ReturnCode_t retcode;
    int i;

    listeners_reader = carBasicInfoDataReader::narrow(reader);
    if (listeners_reader == NULL) {
        printf("DataReader narrow error\n");
        return;
    }

    retcode = listeners_reader->take(
            data_seq,
            info_seq,
            DDS_LENGTH_UNLIMITED,
            DDS_ANY_SAMPLE_STATE,
            DDS_ANY_VIEW_STATE,
            DDS_ANY_INSTANCE_STATE);

    if (retcode == DDS_RETCODE_NO_DATA) {
        return;
    } else if (retcode != DDS_RETCODE_OK) {
        printf("take error %d\n", retcode);
        return;
    }

    for (i = 0; i < data_seq.length(); ++i) {
        /* If the reference we get is valid data, it means we have actual
         * data available, otherwise we got metadata */
        if (info_seq[i].valid_data) {
            std::cout << "Received data" << std::endl;
            carBasicInfoTypeSupport::print_data(&data_seq[i]);
        } else {
            printf("   Got metadata\n");
        }
    }

    retcode = listeners_reader->return_loan(data_seq, info_seq);
    if (retcode != DDS_RETCODE_OK) {
        printf("return loan error %d\n", retcode);
    }
}

// Process data. Returns number of samples processed.
unsigned int process_data(carBasicInfoDataReader *typed_reader)
{
    carBasicInfoSeq data_seq;     // Sequence of received data
    DDS_SampleInfoSeq info_seq; // Metadata associated with samples in data_seq
    unsigned int samples_read = 0;

    // Take available data from DataReader's queue
    typed_reader->take(
        data_seq,
        info_seq,
        DDS_LENGTH_UNLIMITED,
        DDS_ANY_SAMPLE_STATE,
        DDS_ANY_VIEW_STATE,
        DDS_ANY_INSTANCE_STATE);

    // Iterate over all available data
    for (int i = 0; i < data_seq.length(); ++i) {
        // Check if a sample is an instance lifecycle event
        if (info_seq[i].valid_data) {
            // Print data
            std::cout << "Received data" << std::endl;
            carBasicInfoTypeSupport::print_data(&data_seq[i]);
            samples_read++;
        } else {  // This is an instance lifecycle event with no data payload.
            std::cout << "Received instance state notification" << std::endl;
        }
    }
    // Data loaned from Connext for performance. Return loan when done.
    DDS_ReturnCode_t retcode = typed_reader->return_loan(data_seq, info_seq);
    if (retcode != DDS_RETCODE_OK) {
        std::cerr << "return loan error " << retcode << std::endl;
    }

    return samples_read;
}

int run_subscriber_application(unsigned int domain_id, unsigned int sample_count)
{
     /* To load my_custom_qos_profiles.xml, as explained above, we need to modify
     * the  DDSTheParticipantFactory Profile QoSPolicy */
    DDS_DomainParticipantFactoryQos factory_qos;
    DDSTheParticipantFactory->get_qos(factory_qos);

    int count = 0;
    DDS_Duration_t receive_period = { 4, 0 };

    /* We are only going to add one XML file to the url_profile sequence, so we
     * ensure a length of 1,1. */
    factory_qos.profile.url_profile.ensure_length(1, 1);

    /* The XML file will be loaded from the working directory. That means, you
     * need to run the example like this:
     * ./objs/<architecture>/profiles_publisher
     * (see README.txt for more information on how to run the example).
     *
     * Note that you can specify the absolute path of the XML QoS file to avoid
     * this problem.
     */
    factory_qos.profile.url_profile[0] =
            DDS_String_dup("car_basic_info.xml");

    DDSTheParticipantFactory->set_qos(factory_qos);

    // Start communicating in a domain, usually one participant per application
    DDSDomainParticipant *participant =
    DDSTheParticipantFactory->create_participant(
        domain_id,
        DDS_PARTICIPANT_QOS_DEFAULT,
        NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        return shutdown_participant(participant, "create_participant error", EXIT_FAILURE);
    }

    // A Subscriber allows an application to create one or more DataReaders
    DDSSubscriber *subscriber = participant->create_subscriber(
        DDS_SUBSCRIBER_QOS_DEFAULT,
        NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (subscriber == NULL) {
        return shutdown_participant(participant, "create_subscriber error", EXIT_FAILURE);
    }

    // Register the datatype to use when creating the Topic
    const char *type_name = carBasicInfoTypeSupport::get_type_name();
    DDS_ReturnCode_t retcode =
    carBasicInfoTypeSupport::register_type(participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        return shutdown_participant(participant, "register_type error", EXIT_FAILURE);
    }

    // Create a Topic with a name and a datatype
    DDSTopic *topic = participant->create_topic(
        "Example carBasicInfo",
        type_name,
        DDS_TOPIC_QOS_DEFAULT,
        NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        return shutdown_participant(participant, "create_topic error", EXIT_FAILURE);
    }

     /* Create a data reader listener */
    ReaderListener *reader_listener = new ReaderListener();
    if (reader_listener == NULL) {
        delete reader_listener;
         return shutdown_participant(participant, "create_listener error", EXIT_FAILURE);
    }

    // This DataReader reads data on "Example carBasicInfo" Topic
    DDSDataReader *untyped_reader = subscriber->create_datareader_with_profile(
        topic,
        "ExampleTrainingLibrary",
        "ExampleTrainingDurabilityProfile",
        NULL,
        DDS_STATUS_MASK_NONE);
    if (untyped_reader == NULL) {
        return shutdown_participant(participant, "create_datareader error", EXIT_FAILURE);
    }

    // // This DataReader reads data on "Example carBasicInfo" Topic with Listener
    // DDSDataReader *untyped_reader = subscriber->create_datareader_with_profile(
    //     topic,
    //     "ExampleTrainingLibrary",
    //     "ExampleTrainingDurabilityProfile",
    //     reader_listener,
    //     DDS_SUBSCRIPTION_MATCHED_STATUS|
    //     DDS_LIVELINESS_CHANGED_STATUS|
    //     DDS_DATA_AVAILABLE_STATUS);
    // if (untyped_reader == NULL) {
    //     delete reader_listener;
    //     return shutdown_participant(participant, "create_datareader error", EXIT_FAILURE);
    // }

    // Narrow casts from a untyped DataReader to a reader of your type
    carBasicInfoDataReader *typed_reader =
    carBasicInfoDataReader::narrow(untyped_reader);
    if (typed_reader == NULL) {
        return shutdown_participant(participant, "DataReader narrow error", EXIT_FAILURE);
    }

    // Create ReadCondition that triggers when unread data in reader's queue
    DDSReadCondition *read_condition = typed_reader->create_readcondition(
        DDS_NOT_READ_SAMPLE_STATE,
        DDS_ANY_VIEW_STATE,
        DDS_ANY_INSTANCE_STATE);
    if (read_condition == NULL) {
        return shutdown_participant(participant, "create_readcondition error", EXIT_FAILURE);
    }

    // -->UNCOMMENT FOR WAITSET IMPLEMENTATION
    // WaitSet will be woken when the attached condition is triggered
    // DDSWaitSet waitset;
    // retcode = waitset.attach_condition(read_condition);
    // if (retcode != DDS_RETCODE_OK) {
    //     return shutdown_participant(participant, "attach_condition error", EXIT_FAILURE);
    // }

    // Main loop. Wait for data to arrive, and process when it arrives
    // unsigned int samples_read = 0;
    // while (!shutdown_requested && samples_read < sample_count) {
    //     DDSConditionSeq active_conditions_seq;

    //     // Wait for data and report if it does not arrive in 1 second
    //     DDS_Duration_t wait_timeout = { 1, 0 };
    //     retcode = waitset.wait(active_conditions_seq, wait_timeout);

    //     if (retcode == DDS_RETCODE_OK) {
    //         // If the read condition is triggered, process data
    //         samples_read += process_data(typed_reader);
    //     } else {
    //         if (retcode == DDS_RETCODE_TIMEOUT) {
    //             std::cout << "No data after 1 second" << std::endl;
    //         }
    //     }
    // }
    // <--UNCOMMENT FOR WAITSET IMPLEMENTATION
    
    // -->UNCOMMENT FOR POLLING IMPLEMENTATION
    /* Main loop */
    // for (count = 0; (sample_count == 0) || (count < sample_count); ++count) {
    //     NDDSUtility::sleep(receive_period);
    // }
    // <--UNCOMMENT FOR LISTENER IMPLEMENTATION

        // -->UNCOMMENT FOR LISTENER IMPLEMENTATION
    /* Main loop */
    for (count = 0; (!shutdown_requested) && ((sample_count == 0) || (count < sample_count)); ++count) {
 
    carBasicInfoSeq data_seq;     // Sequence of received data
    DDS_SampleInfoSeq info_seq; // Metadata associated with samples in data_seq
  
    std::cout << "Read Loop" << std::endl;
    NDDSUtility::sleep(receive_period);
 
    // Take available data from DataReader's queue
    typed_reader->take(
        data_seq,
        info_seq,
        DDS_LENGTH_UNLIMITED,
        DDS_ANY_SAMPLE_STATE,
        DDS_ANY_VIEW_STATE,
        DDS_ANY_INSTANCE_STATE);

    // Iterate over all available data
    for (int i = 0; i < data_seq.length(); ++i) {
        // Check if a sample is an instance lifecycle event
        if (info_seq[i].valid_data) {
            // Print data
            std::cout << "Received data" << std::endl;
            carBasicInfoTypeSupport::print_data(&data_seq[i]);
         } else {  // This is an instance lifecycle event with no data payload.
            std::cout << "Invalid data" << std::endl;
        }
    }
    // Data loaned from Connext for performance. Return loan when done.
    DDS_ReturnCode_t retcode = typed_reader->return_loan(data_seq, info_seq);
    if (retcode != DDS_RETCODE_OK) {
        std::cerr << "return loan error " << retcode << std::endl;
    }
    }
    // <--UNCOMMENT FOR POLLING IMPLEMENTATION



    // Cleanup
    return shutdown_participant(participant, "Shutting down", 0);
}

// Delete all entities
static int shutdown_participant(
    DDSDomainParticipant *participant,
    const char *shutdown_message,
    int status)
{
    DDS_ReturnCode_t retcode;

    std::cout << shutdown_message << std::endl;

    if (participant != NULL) {
        // Cleanup everything created by this Participant
        retcode = participant->delete_contained_entities();
        if (retcode != DDS_RETCODE_OK) {
            std::cerr << "delete_contained_entities error" << retcode
            << std::endl;
            status = EXIT_FAILURE;
        }

        retcode = DDSTheParticipantFactory->delete_participant(participant);
        if (retcode != DDS_RETCODE_OK) {
            std::cerr << "delete_participant error" << retcode << std::endl;
            status = EXIT_FAILURE;
        }
    }
    return status;
}

int main(int argc, char *argv[])
{

    // Parse arguments and handle control-C
    ApplicationArguments arguments;
    parse_arguments(arguments, argc, argv);
    if (arguments.parse_result == PARSE_RETURN_EXIT) {
        return EXIT_SUCCESS;
    } else if (arguments.parse_result == PARSE_RETURN_FAILURE) {
        return EXIT_FAILURE;
    }
    setup_signal_handlers();

    // Sets Connext verbosity to help debugging
    NDDSConfigLogger::get_instance()->set_verbosity(arguments.verbosity);

    int status = run_subscriber_application(arguments.domain_id, arguments.sample_count);

    // Releases the memory used by the participant factory.  Optional at
    // application exit
    DDS_ReturnCode_t retcode = DDSDomainParticipantFactory::finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        std::cerr << "finalize_instance error" << retcode << std::endl;
        status = EXIT_FAILURE;
    }

    return status;
}

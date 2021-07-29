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

class DataWriterListener : public DDSDataWriterListener {
public:
    virtual void on_offered_deadline_missed(
            DDSDataWriter * /*writer*/,
            const DDS_OfferedDeadlineMissedStatus & /*status*/)
    {
        printf("DataWriterListener: on_offered_deadline_missed()\n");
    }

    virtual void on_liveliness_lost(
            DDSDataWriter * /*writer*/,
            const DDS_LivelinessLostStatus & /*status*/)
    {
        printf("DataWriterListener: on_liveliness_lost()\n");
    }

    virtual void on_offered_incompatible_qos(
            DDSDataWriter * /*writer*/,
            const DDS_OfferedIncompatibleQosStatus & /*status*/)
    {
        printf("DataWriterListener: on_offered_incompatible_qos()\n");
    }

    virtual void on_publication_matched(
            DDSDataWriter *writer,
            const DDS_PublicationMatchedStatus &status)
    {
        printf("DataWriterListener: on_publication_matched() - FROM ZHIKAI\n");
        if (status.current_count_change < 0) {
            printf("lost a subscription\n");
        } else {
            printf("found a subscription\n");
        }
    }

    virtual void on_reliable_writer_cache_changed(
            DDSDataWriter *writer,
            const DDS_ReliableWriterCacheChangedStatus &status)
    {
        printf("DataWriterListener: on_reliable_writer_cache_changed()\n");
    }

    virtual void on_reliable_reader_activity_changed(
            DDSDataWriter *writer,
            const DDS_ReliableReaderActivityChangedStatus &status)
    {
        printf("DataWriterListener: on_reliable_reader_activity_changed()\n");
    }
};

static int shutdown_participant(
    DDSDomainParticipant *participant,
    const char *shutdown_message,
    int status);

int run_publisher_application(unsigned int domain_id, unsigned int sample_count)
{

    /* To load my_custom_qos_profiles.xml, as explained above, we need to modify
     * the  DDSTheParticipantFactory Profile QoSPolicy */
    // DDS_DomainParticipantFactoryQos factory_qos;
    // DDSTheParticipantFactory->get_qos(factory_qos);

    /* We are only going to add one XML file to the url_profile sequence, so we
     * ensure a length of 1,1. */
    // factory_qos.profile.url_profile.ensure_length(1, 1);

    /* The XML file will be loaded from the working directory. That means, you
     * need to run the example like this:
     * ./objs/<architecture>/profiles_publisher
     * (see README.txt for more information on how to run the example).
     *
     * Note that you can specify the absolute path of the XML QoS file to avoid
     * this problem.
     */
    // factory_qos.profile.url_profile[0] =
    //         DDS_String_dup("car_basic_info.xml");

    // DDSTheParticipantFactory->set_qos(factory_qos);

    DDS_DomainParticipantQos participant_qos;
    DDSTheParticipantFactory->get_default_participant_qos(participant_qos);

//     /* free original memory */
//     participant_qos.discovery.initial_peers.maximum(0);
    
//    /* set new initial peer for sending discovery information  */
//     participant_qos.discovery.initial_peers.maximum(3);
//     participant_qos.discovery.initial_peers.length(3);
//     //participant_qos.discovery.initial_peers[0] = DDS_String_dup("239.255.0.2");
//     participant_qos.discovery.initial_peers[0] = DDS_String_dup("4@builtin.udpv4://192.168.1.111");
//     participant_qos.discovery.initial_peers[1] = DDS_String_dup("4@builtin.udpv4://127.0.0.1");
//     participant_qos.discovery.initial_peers[2] = DDS_String_dup("builtin.shmem://");
//     //participant_qos.discovery.initial_peers[3] = DDS_String_dup("4@builtin.udpv4://192.168.1.123");
      
//     /* free original memory */
//     participant_qos.discovery.multicast_receive_addresses.maximum(0);
    
//     /* set new multicast receive address for receiving multicast
//     discovery information */
//     participant_qos.discovery.multicast_receive_addresses.maximum(1);
//     participant_qos.discovery.multicast_receive_addresses.length(1);
//     participant_qos.discovery.multicast_receive_addresses[0] =    DDS_String_dup("239.255.0.2");    
    
    // Start communicating in a domain, usually one participant per application
    DDSDomainParticipant *participant =
    DDSTheParticipantFactory->create_participant(
        domain_id,
        //DDS_PARTICIPANT_QOS_DEFAULT,
        participant_qos,
        NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        return shutdown_participant(participant, "create_participant error", EXIT_FAILURE);
    }




    // A Publisher allows an application to create one or more DataWriters
    DDSPublisher *publisher = participant->create_publisher(
        DDS_PUBLISHER_QOS_DEFAULT,
        NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (publisher == NULL) {
        return shutdown_participant(participant, "create_publisher error", EXIT_FAILURE);
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

    // // This DataWriter writes data on "Example carBasicInfo" Topic
    // DDSDataWriter *untyped_writer = publisher->create_datawriter(
    //     topic,
    //     DDS_DATAWRITER_QOS_DEFAULT,
    //     NULL /* listener */,
    //     DDS_STATUS_MASK_NONE);
    // if (untyped_writer == NULL) {
    //     return shutdown_participant(participant, "create_datawriter error", EXIT_FAILURE);
    // }

/* We will use the Data Writer Listener defined above to print
     * a message when some of events are triggered in the DataWriter.
     * To do that, first we have to pass the writer_listener and then
     * we have to enable all status in the status mask.
     */
    DataWriterListener *writer_listener = new DataWriterListener();
    DDS_StatusMask mask = DDS_PUBLICATION_MATCHED_STATUS;

     // This DataWriter writes data on "Example carBasicInfo" Topic
    DDSDataWriter *untyped_writer = publisher->create_datawriter_with_profile(
        topic,
        //"ExampleTrainingLibrary",
        //"ExampleTrainingDurabilityProfile",
        "car_basic_info_Library",
        "car_basic_info_Profile",
        writer_listener /* listener */,
        mask);
    if (untyped_writer == NULL) {
        delete writer_listener;
        return shutdown_participant(participant, "create_datawriter error", EXIT_FAILURE);
    }

    // Narrow casts from an untyped DataWriter to a writer of your type 
    carBasicInfoDataWriter *typed_writer =
    carBasicInfoDataWriter::narrow(untyped_writer);
    if (typed_writer == NULL) {
        return shutdown_participant(participant, "DataWriter narrow error", EXIT_FAILURE);
    }

    // Create data for writing, allocating all members
    carBasicInfo *dataA = carBasicInfoTypeSupport::create_data();
    if (dataA == NULL) {
        return shutdown_participant(
            participant,
            "carBasicInfoTypeSupport::create_data error",
            EXIT_FAILURE);
    }

    // Create data for writing, allocating all members
    carBasicInfo *dataB = carBasicInfoTypeSupport::create_data();
    if (dataB == NULL) {
        return shutdown_participant(
            participant,
            "carBasicInfoTypeSupport::create_data error",
            EXIT_FAILURE);
    }


    DDS_InstanceHandle_t instanceHandleA;
    DDS_InstanceHandle_t instanceHandleB;

    // Main loop, write data
    for (unsigned int samples_written = 0;
    !shutdown_requested && samples_written < sample_count;
    ++samples_written) {

        // Modify the data to be written here

        //Send 1st instance
        dataA->licenceNumber = DDS_String_dup("ABC1234");

        instanceHandleA = typed_writer->register_instance(*dataA);
        
        dataA->speed = static_cast<DDS_Short>(samples_written);
        dataA->posX=(double)rand()/(double)RAND_MAX*255;
        dataA->posY=(double)rand()/(double)RAND_MAX*255;

        std::cout << "Writing carBasicInfo, count " << samples_written 
        << std::endl;
        retcode = typed_writer->write(*dataA, instanceHandleA);
        if (retcode != DDS_RETCODE_OK) {
            std::cerr << "write error " << retcode << std::endl;
        }

        //Send 2nd instance
        dataB->licenceNumber = DDS_String_dup("XYZ3456");

        instanceHandleB = typed_writer->register_instance(*dataB);
        
        dataB->speed = static_cast<DDS_Short>(samples_written);
        dataB->posX=(double)rand()/(double)RAND_MAX*255;
        dataB->posY=(double)rand()/(double)RAND_MAX*255;

        std::cout << "Writing carBasicInfo, count " << samples_written 
        << std::endl;
        retcode = typed_writer->write(*dataB, instanceHandleB);
        if (retcode != DDS_RETCODE_OK) {
            std::cerr << "write error " << retcode << std::endl;
        }

        // Send once every second
        DDS_Duration_t send_period = { 1, 0 };
        NDDSUtility::sleep(send_period);
    }

    typed_writer->unregister_instance(*dataA,instanceHandleA);
    typed_writer->unregister_instance(*dataB,instanceHandleB);

    // Delete previously allocated carBasicInfo, including all contained elements
    retcode = carBasicInfoTypeSupport::delete_data(dataA);
    if (retcode != DDS_RETCODE_OK) {
        std::cerr << "carBasicInfoTypeSupport::delete_data error " << retcode
        << std::endl;
    }

    // Delete previously allocated carBasicInfo, including all contained elements
    retcode = carBasicInfoTypeSupport::delete_data(dataB);
    if (retcode != DDS_RETCODE_OK) {
        std::cerr << "carBasicInfoTypeSupport::delete_data error " << retcode
        << std::endl;
    }

    // Delete all entities (DataWriter, Topic, Publisher, DomainParticipant)
    return shutdown_participant(participant, "Shutting down", EXIT_SUCCESS);
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
            std::cerr << "delete_contained_entities error " << retcode
            << std::endl;
            status = EXIT_FAILURE;
        }

        retcode = DDSTheParticipantFactory->delete_participant(participant);
        if (retcode != DDS_RETCODE_OK) {
            std::cerr << "delete_participant error " << retcode << std::endl;
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

    int status = run_publisher_application(arguments.domain_id, arguments.sample_count);

    // Releases the memory used by the participant factory.  Optional at
    // application exit
    DDS_ReturnCode_t retcode = DDSDomainParticipantFactory::finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        std::cerr << "finalize_instance error " << retcode << std::endl;
        status = EXIT_FAILURE;
    }

    return status;
}




/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from car_basic_info.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef car_basic_infoPlugin_1168497325_h
#define car_basic_infoPlugin_1168497325_h

#include "car_basic_info.h"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

extern "C"{

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct carBasicInfo
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct carBasicInfo)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * carBasicInfo must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct carBasicInfo.
    */
    typedef  class carBasicInfo carBasicInfoKeyHolder;

    #define carBasicInfoPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define carBasicInfoPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define carBasicInfoPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define carBasicInfoPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define carBasicInfoPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define carBasicInfoPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define carBasicInfoPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern carBasicInfo*
    carBasicInfoPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern carBasicInfo*
    carBasicInfoPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern carBasicInfo*
    carBasicInfoPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    carBasicInfoPluginSupport_copy_data(
        carBasicInfo *out,
        const carBasicInfo *in);

    NDDSUSERDllExport extern void 
    carBasicInfoPluginSupport_destroy_data_w_params(
        carBasicInfo *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    carBasicInfoPluginSupport_destroy_data_ex(
        carBasicInfo *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    carBasicInfoPluginSupport_destroy_data(
        carBasicInfo *sample);

    NDDSUSERDllExport extern void 
    carBasicInfoPluginSupport_print_data(
        const carBasicInfo *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern carBasicInfo*
    carBasicInfoPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern carBasicInfo*
    carBasicInfoPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    carBasicInfoPluginSupport_destroy_key_ex(
        carBasicInfoKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    carBasicInfoPluginSupport_destroy_key(
        carBasicInfoKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    carBasicInfoPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    carBasicInfoPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    carBasicInfoPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    carBasicInfoPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    carBasicInfoPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        carBasicInfo *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    carBasicInfoPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        carBasicInfo *out,
        const carBasicInfo *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    carBasicInfoPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const carBasicInfo *sample); 

    NDDSUSERDllExport extern RTIBool
    carBasicInfoPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const carBasicInfo *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    carBasicInfoPlugin_deserialize_from_cdr_buffer(
        carBasicInfo *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    carBasicInfoPlugin_data_to_string(
        const carBasicInfo *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    carBasicInfoPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    carBasicInfoPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    carBasicInfoPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    carBasicInfoPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    carBasicInfoPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        carBasicInfo ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    carBasicInfoPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        carBasicInfoKeyHolder *key, 
        const carBasicInfo *instance);

    NDDSUSERDllExport extern RTIBool 
    carBasicInfoPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        carBasicInfo *instance, 
        const carBasicInfoKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    carBasicInfoPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * carBasicInfoPlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    carBasicInfoPlugin_new(void);

    NDDSUSERDllExport extern void
    carBasicInfoPlugin_delete(struct PRESTypePlugin *);

}

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* car_basic_infoPlugin_1168497325_h */


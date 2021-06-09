

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from car_basic_info.idl 
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#ifndef dds_c_log_impl_h              
#include "dds_c/dds_c_log_impl.h"                                
#endif 
#ifndef dds_c_log_infrastructure_h                      
#include "dds_c/dds_c_infrastructure_impl.h"       
#endif 

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#else
#include "ndds_standalone_type.h"
#endif

#include "car_basic_info.h"

#ifndef NDDS_STANDALONE_TYPE
#include "car_basic_infoPlugin.h"
#endif

#include <new>

/* ========================================================================= */
const char *carBasicInfoTYPENAME = "carBasicInfo";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode * carBasicInfo_get_typecode(void)
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode carBasicInfo_g_tc_licenceNumber_string = DDS_INITIALIZE_STRING_TYPECODE((16L));

    static DDS_TypeCode_Member carBasicInfo_g_tc_members[4]=
    {

        {
            (char *)"licenceNumber",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_KEY_MEMBER , /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"speed",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"posX",/* Member name */
            {
                2,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"posY",/* Member name */
            {
                3,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode carBasicInfo_g_tc =
    {{
            DDS_TK_STRUCT| DDS_TK_MUTABLE_EXTENSIBILITY, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"carBasicInfo", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            carBasicInfo_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for carBasicInfo*/

    if (is_initialized) {
        return &carBasicInfo_g_tc;
    }

    carBasicInfo_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    carBasicInfo_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&carBasicInfo_g_tc_licenceNumber_string;
    carBasicInfo_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short_w_new;
    carBasicInfo_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    carBasicInfo_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float_w_new;

    /* Initialize the values for member annotations. */
    carBasicInfo_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    carBasicInfo_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    carBasicInfo_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_SHORT;
    carBasicInfo_g_tc_members[1]._annotations._defaultValue._u.short_value = 0;
    carBasicInfo_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_SHORT;
    carBasicInfo_g_tc_members[1]._annotations._minValue._u.short_value = RTIXCdrShort_MIN;
    carBasicInfo_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_SHORT;
    carBasicInfo_g_tc_members[1]._annotations._maxValue._u.short_value = RTIXCdrShort_MAX;

    carBasicInfo_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    carBasicInfo_g_tc_members[2]._annotations._defaultValue._u.float_value = 0.0f;
    carBasicInfo_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    carBasicInfo_g_tc_members[2]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    carBasicInfo_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    carBasicInfo_g_tc_members[2]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    carBasicInfo_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    carBasicInfo_g_tc_members[3]._annotations._defaultValue._u.float_value = 0.0f;
    carBasicInfo_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    carBasicInfo_g_tc_members[3]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    carBasicInfo_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    carBasicInfo_g_tc_members[3]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    carBasicInfo_g_tc._data._sampleAccessInfo =
    carBasicInfo_get_sample_access_info();
    carBasicInfo_g_tc._data._typePlugin =
    carBasicInfo_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &carBasicInfo_g_tc;
}

#define TSeq carBasicInfoSeq
#define T carBasicInfo
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *carBasicInfo_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo carBasicInfo_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(carBasicInfoSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        carBasicInfoSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &carBasicInfo_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *carBasicInfo_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    carBasicInfo *sample;

    static RTIXCdrMemberAccessInfo carBasicInfo_g_memberAccessInfos[4] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo carBasicInfo_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &carBasicInfo_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        carBasicInfo);
    if (sample == NULL) {
        return NULL;
    }

    carBasicInfo_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->licenceNumber - (char *)sample);

    carBasicInfo_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->speed - (char *)sample);

    carBasicInfo_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->posX - (char *)sample);

    carBasicInfo_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->posY - (char *)sample);

    carBasicInfo_g_sampleAccessInfo.memberAccessInfos = 
    carBasicInfo_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(carBasicInfo);

        if (candidateTypeSize > RTIXCdrLong_MAX) {
            carBasicInfo_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrLong_MAX;
        } else {
            carBasicInfo_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    carBasicInfo_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    carBasicInfo_g_sampleAccessInfo.getMemberValuePointerFcn = 
    carBasicInfo_get_member_value_pointer;

    carBasicInfo_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &carBasicInfo_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *carBasicInfo_get_type_plugin_info()
{
    static RTIXCdrTypePlugin carBasicInfo_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        carBasicInfo_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        carBasicInfo_finalize_w_return,
        NULL
    };

    return &carBasicInfo_g_typePlugin;
}
#endif

RTIBool carBasicInfo_initialize(
    carBasicInfo* sample) {
    return carBasicInfo_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool carBasicInfo_initialize_ex(
    carBasicInfo* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return carBasicInfo_initialize_w_params(
        sample,&allocParams);

}

RTIBool carBasicInfo_initialize_w_params(
    carBasicInfo* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory) {
        sample->licenceNumber = DDS_String_alloc((16L));
        RTICdrType_copyStringEx(
            &sample->licenceNumber,
            "",
            (16L),
            RTI_FALSE);
        if (sample->licenceNumber == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->licenceNumber != NULL) {
            RTICdrType_copyStringEx(
                &sample->licenceNumber,
                "",
                (16L),
                RTI_FALSE);
            if (sample->licenceNumber == NULL) {
                return RTI_FALSE;
            }
        }
    }

    sample->speed = 0;

    sample->posX = 0.0f;

    sample->posY = 0.0f;

    return RTI_TRUE;
}

RTIBool carBasicInfo_finalize_w_return(
    carBasicInfo* sample)
{
    carBasicInfo_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void carBasicInfo_finalize(
    carBasicInfo* sample)
{

    carBasicInfo_finalize_ex(sample,RTI_TRUE);
}

void carBasicInfo_finalize_ex(
    carBasicInfo* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    carBasicInfo_finalize_w_params(
        sample,&deallocParams);
}

void carBasicInfo_finalize_w_params(
    carBasicInfo* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    if (sample->licenceNumber != NULL) {
        DDS_String_free(sample->licenceNumber);
        sample->licenceNumber=NULL;

    }

}

void carBasicInfo_finalize_optional_members(
    carBasicInfo* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool carBasicInfo_copy(
    carBasicInfo* dst,
    const carBasicInfo* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyStringEx (
            &dst->licenceNumber, src->licenceNumber, 
            (16L) + 1, RTI_FALSE)){
            return RTI_FALSE;
        }
        if (!RTICdrType_copyShort (
            &dst->speed, &src->speed)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->posX, &src->posX)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->posY, &src->posY)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'carBasicInfo' sequence class.
*/
#define T carBasicInfo
#define TSeq carBasicInfoSeq

#define T_initialize_w_params carBasicInfo_initialize_w_params

#define T_finalize_w_params   carBasicInfo_finalize_w_params
#define T_copy       carBasicInfo_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

#ifndef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace xcdr {
        const RTIXCdrTypeCode * type_code<carBasicInfo>::get() 
        {
            return (const RTIXCdrTypeCode *) carBasicInfo_get_typecode();
        }

    } 
}
#endif

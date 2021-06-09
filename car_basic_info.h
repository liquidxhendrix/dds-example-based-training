

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from car_basic_info.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef car_basic_info_1168497325_h
#define car_basic_info_1168497325_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#include "rti/xcdr/Interpreter.hpp"
#else
#include "ndds_standalone_type.h"
#endif

extern "C" {

    extern const char *carBasicInfoTYPENAME;

}

struct carBasicInfoSeq;
#ifndef NDDS_STANDALONE_TYPE
class carBasicInfoTypeSupport;
class carBasicInfoDataWriter;
class carBasicInfoDataReader;
#endif
class carBasicInfo 
{
  public:
    typedef struct carBasicInfoSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef carBasicInfoTypeSupport TypeSupport;
    typedef carBasicInfoDataWriter DataWriter;
    typedef carBasicInfoDataReader DataReader;
    #endif

    DDS_Char *   licenceNumber ;
    DDS_Short   speed ;
    DDS_Float   posX ;
    DDS_Float   posY ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode * carBasicInfo_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *carBasicInfo_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *carBasicInfo_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *carBasicInfo_get_sample_seq_access_info(void);
#endif

DDS_SEQUENCE(carBasicInfoSeq, carBasicInfo);

NDDSUSERDllExport
RTIBool carBasicInfo_initialize(
    carBasicInfo* self);

NDDSUSERDllExport
RTIBool carBasicInfo_initialize_ex(
    carBasicInfo* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool carBasicInfo_initialize_w_params(
    carBasicInfo* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool carBasicInfo_finalize_w_return(
    carBasicInfo* self);

NDDSUSERDllExport
void carBasicInfo_finalize(
    carBasicInfo* self);

NDDSUSERDllExport
void carBasicInfo_finalize_ex(
    carBasicInfo* self,RTIBool deletePointers);

NDDSUSERDllExport
void carBasicInfo_finalize_w_params(
    carBasicInfo* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void carBasicInfo_finalize_optional_members(
    carBasicInfo* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool carBasicInfo_copy(
    carBasicInfo* dst,
    const carBasicInfo* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#ifndef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace xcdr {
        template <>
        struct type_code<carBasicInfo> {
            static const RTIXCdrTypeCode * get();
        };

    } 
}

#endif

#endif /* car_basic_info */


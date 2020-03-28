//
//  DSSN_Tile.h
//  ReportServiceCore
//
//  Created by Zhang Jia on 7/20/11.
//  Copyright 2011 MicroStrategy Beijing R&D Center. All rights reserved.
//

#ifndef N_Tile_h
#define N_Tile_h 1

#import "DSSGenericFunction.h"
#import "../Common/Base/Base/Allocator.h"
#import "VariantCommonInclude.h"

class DSSN_Tile : public DSSGenericFunction
{    
public:
    DSSN_Tile();
    
    ~DSSN_Tile();
    
    // int Init (EnumDSSFunction iFunctionIndex);
    
    virtual HRESULT setProperty (Int32 Index, CComVariant *pValue);
    
    HRESULT Calculate ();
    
    HRESULT GetOutput (Int32 nSize,       // Input buffer size
                   Int32 *nDataSize,  // return data size
                   double *pData,     // Double array stores the result of function
                   DSSDataFlag *pFlag // Output flags
                   );
    
    int GetOutput(Int32, Int32 *, VARIANT *, DSSDataFlag *);
    
    HRESULT GetOutputType (EnumDSSParameterType *  pType);
    
    HRESULT GetOutputType(Int32, EnumDSSDataType *, EnumDSSDataType *, EnumDSSParameterType *);
    
    int Clear ();
    
    HRESULT SetInputParam (Int32 nParamIndex, // The index of input parameter
                       Int32 nSize,       // Size of input double array
                       double *pData,
                       DSSDataFlag *pFlag);
    
    HRESULT SetInputParam(Int32, Int32, EnumDSSDataType,CComVariant *, DSSDataFlag *);
    
    HRESULT GetInputParamType (Int32 nParamIndex, EnumDSSParameterType *pType);
    
    HRESULT IsNullProcessable(bool *pCanProcessNULL); 
    
    // jxie, 2010-10-11
    // support direct calculate
    virtual HRESULT DirectCalculate (Int32 nParam, Int32* ipSize, Int32** ipOffsets, 
                         void** ipData, double* ipDivider, DSSDataFlag** ipFlags, VARIANT_BOOL* ipAllDataValid,
                         EnumDSSDataType* iType, vector<Int32> * ipvDataByGroup,
                         Int32 nResSize, double* opData, DSSDataFlag* opFlag, VARIANT_BOOL* opAllDataValid, 
                         EnumNullCheckingOption iNullCheckingOption);
    
    virtual bool SupportDirectCalculate();
    
private:    
    double *mpData;
    Int32 mnDataSize;    
    double *mpResults;    
    Int32 mNBuckets;
    bool mAsc;    
    double mStepValue; //step value for NTile_SV
};

#endif

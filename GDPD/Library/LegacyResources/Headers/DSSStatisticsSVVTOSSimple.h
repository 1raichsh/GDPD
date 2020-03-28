//
//  DSSStatisticsSVVTOSSimple.h
//  ReportServiceCore
//
//  Created by He Tengfei on 3/7/12.
//  Copyright 2012 MicroStrategy, Inc. All rights reserved.
//
#ifndef DSSStatisticsSVVTOSSimple_h
#define DSSStatisticsSVVTOSSimple_h 1

#include "DSSGenericFunction.h"

class DSSStatisticsSVVTOSSimple:public DSSGenericFunction
{
public:
    DSSStatisticsSVVTOSSimple();
    
    ~DSSStatisticsSVVTOSSimple();
    
    HRESULT setProperty (Int32 Index, CComVariant *pValue);
    
    int Init (Int32 iFunctionIndex);
    
    HRESULT Calculate ();
    
    HRESULT GetOutput (Int32 nSize, Int32 *nDataSize, double *pData, DSSDataFlag *pFlag);
    
    HRESULT GetOutputType (EnumDSSParameterType *pType);
    
    HRESULT SetInputParam (Int32 nParamIndex, Int32 nSize, double *pData, DSSDataFlag *pFlag);
    
    HRESULT GetInputParamType (Int32 nParamIndex, EnumDSSParameterType *pType);
    
    int Clear ();
    
    HRESULT IsNullProcessable (bool *pCanProcessNULL);

private:
    Int32 mFunctionIndex;
    Int32 mVSize1;
    double *mV1;
    Int32 mVSize2;
    double *mV2;
    double mS;
    double mResult; 
    DSSDataFlag mFlag;
};

#endif

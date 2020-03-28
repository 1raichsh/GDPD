//
//  DSSStatisticsGeneric.h
//  ReportServiceCore
//
//  Created by He Tengfei on 3/7/12.
//  Copyright 2012 MicroStrategy, Inc. All rights reserved.
//

#ifndef DSSStatisticsGeneric_h
#define DSSStatisticsGeneric_h 1

#include "DSSGenericFunction.h"
#include "statistic.h"

class DSSStatisticsGeneric :public DSSGenericFunction
{
public:
    DSSStatisticsGeneric();
    
    ~DSSStatisticsGeneric();
    
    HRESULT Calculate();
    
    HRESULT GetOutput(Int32 nSize, Int32 *nDataSize, double *pData, DSSDataFlag *pFlag);
    
    HRESULT GetOutputType(EnumDSSParameterType *pType);
    
    HRESULT SetInputParam(Int32 nParamIndex, Int32 nSize, double *pData, DSSDataFlag *pFlag);
    
    HRESULT GetInputParamType(Int32 nParamIndex, EnumDSSParameterType *pType);
    
    int Clear();    
    
    HRESULT IsNullProcessable(bool *pCanProcessNULL);
    
    int Init (Int32 iFunctionIndex);
    
    HRESULT setProperty(int Index, CComVariant *ipVal);
    
private:
    Int32 mFunctionIndex;
    enum Hypothesis mHypothesis;
    double moffset;
    Int32 mlenght1;
    double *mvector1;
    Int32 mlenght2;
    double *mvector2;
};

#endif

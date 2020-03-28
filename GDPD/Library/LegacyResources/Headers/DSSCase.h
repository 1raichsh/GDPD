//
//  DSSCase.h
//  ReportServiceCore
//
//  Created by Yang Zhuo on 7/20/11.
//  Copyright 2011 Microstrategy. All rights reserved.
//

#ifndef DSSCASE_H
#define DSSCASE_H

#include "DSSNNGenericFunction.h"

class DSSCase : public DSSNNGenericFunction
{
public:
    DSSCase();
    ~DSSCase();
    
    virtual HRESULT setProperty(Int32 index, CComVariant *pValue);
    HRESULT Calculate();
    HRESULT SetInputParam(Int32 nParamIndex, Int32 nSize, EnumDSSDataType dataType, CComVariant *pData, DSSDataFlag *pFlag);
    HRESULT GetOutput(Int32 nSize, Int32 *nDataSize, CComVariant *pData, DSSDataFlag *pFlag);
    HRESULT GetOutputType (Int32 nSize, EnumDSSDataType *pInputType, 
                       EnumDSSDataType *pOutputDataType, EnumDSSParameterType *pOutParamType);
    HRESULT GetInputParamType(Int32 nParamIndex, EnumDSSParameterType *pType);
    HRESULT IsNullProcessable(bool *pCanProcessNull);
    int Clear();
    HRESULT GetOutput(Int32 nSize, Int32* nDataSize, double *pData, DSSDataFlag *pflag);
    HRESULT GetOutputType(EnumDSSParameterType *pType);
    HRESULT SetInputParam(Int32 nParamIndex, Int32 nSize, double *pData, DSSDataFlag *pFlag);
private:
    Int32 mDataSize;
    vector<DSSDataFlag> mvDataFlag;
    vector<CComVariant *> mvInputData;
    CComVariant mResultData;
    DSSDataFlag mResultFlag;
    bool mfIsNumeric;
    double mNumericResultData;
    vector<double> mvNumericInputData;
    
    int CopyParamOut(long index, CComVariant *pResult);
    HRESULT GetParamFromVariant(long index, EnumDSSDataType type, unsigned char *opResult, Int32 size);
    int CmpDataTypes(EnumDSSDataType type1, EnumDSSDataType type2, EnumDSSDataType *opOutputType);
    int CmpParams(Int32 index1, Int32 index2, bool *fEqual);
    int hCalculateNumeric();
    int CmpNumericParams(Int32 index1, Int32 index2, bool *fEqual);
};

#endif

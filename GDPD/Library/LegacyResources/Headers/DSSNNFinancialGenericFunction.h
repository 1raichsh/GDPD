//
//  DSSNNFinancialGenericFunction.h
//  ReportServiceCore
//
//  Created by He Tengfei on 2/22/12.
//  Copyright 2012 MicroStrategy, Inc. All rights reserved.
//

#ifndef DSSNNFinancialGenericFunction_h
#define DSSNNFinancialGenericFunction_h 1

#include "DSSNNGenericFunction.h"

class DSSDateTime;

class DSSNNFinancialGenericFunction: public DSSNNGenericFunction
{
public:
    DSSNNFinancialGenericFunction();
    
    ~DSSNNFinancialGenericFunction();
    
    HRESULT GetOutput(Int32 nSize, 	// Input buffer size
                  Int32 *nDataSize, 	// return data size
                  CComVariant *pData, 	// Double array stores the result of function
                  DSSDataFlag *pFlag);	// Output flags);    
    
    HRESULT GetOutputType(Int32 nSize, EnumDSSDataType *pInputType,
                                   EnumDSSDataType *pOutputDataType, EnumDSSParameterType *pOutParamType);
    
    HRESULT SetInputParam(Int32 nParamIndex, 	// The index of input parameter
                      Int32 nSize, 	// Size of variant, if size >1, then pData is an array of VARIANTs
                      EnumDSSDataType dataType,
                      CComVariant *pData,
                      DSSDataFlag *pFlag);   
    
    HRESULT Calculate();
    
    HRESULT Init(Int32 iFunctionIndex);
    
    HRESULT setProperty (Int32 Index, CComVariant *pValue);
    
    HRESULT GetOutput(Int32, Int32 *, double *, DSSDataFlag *);
    
    HRESULT GetOutputType(EnumDSSParameterType *);
    
    HRESULT SetInputParam(Int32, Int32, double *, DSSDataFlag *);
    
    HRESULT GetInputParamType(Int32, EnumDSSParameterType *);
    
    
    HRESULT IsNullProcessable(bool *);
    
    int Clear();
    
private:
    Int32 mFunctionIndex;
    
    double mGuess;
    
    double *mpValues; 
    
    Int32   mnValueSize; //The number of elements in mpValues
    
    MDataType::DSSDateTime *mpDates; 
    
    Int32	mnDateSize; //The number of elements in mpDates
    
    Int32 *mpValid; //a value of 2 means both the value and the data are valid
    
    double mRate;
    
    bool	mbRateReady;	// if Rate value is ready
    
    double mfResult;		// store the result of caculate
    DSSDataFlag mFlag;    // store the result flag
    
    int getParamFromVariant(VARIANT *pParam, LONG index, 
                        EnumDSSDataType type, BYTE *outResult,Int32 size);
    
    bool dataTypeAssignmentCompatible(EnumDSSDataType sourceType, EnumDSSDataType destType);
};
#endif

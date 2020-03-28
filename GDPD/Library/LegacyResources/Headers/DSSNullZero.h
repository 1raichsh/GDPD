//
//  DSSNullZero.h
//  ReportServiceCore
//
//  Created by Zhang Jia on 7/22/11.
//  Copyright 2011 MicroStrategy Beijing R&D Center. All rights reserved.
//

#ifndef NullZero_h
#define NullZero_h 1

#import "DSSNNGenericFunction.h"
#import "../Common/Base/Base/Allocator.h"

class DSSNullZero : public DSSNNGenericFunction
{
public:
    DSSNullZero();
    
    ~DSSNullZero();
    
    //	No property for the IsNull function. return E_NOTIMPL.
    virtual HRESULT setProperty (Int32 Index, CComVariant *pValue);
    
    //	This method is to accomplish the calculation.
    HRESULT Calculate ();
    
    HRESULT GetOutput (Int32 nSize,         // Input buffer size
                   Int32 *nDataSize,    // return data size
                   CComVariant *pData,      // Double array stores the result of function
                   DSSDataFlag *pFlag   // Output flags
                   );
    
    HRESULT GetOutputType (Int32 nSize, EnumDSSDataType *pInputType, EnumDSSDataType *pOutputDataType, EnumDSSParameterType *pOutputParamType);
    
    //	This method is to set the input parameter.
    HRESULT SetInputParam (Int32 nParamIndex, Int32 nSize, EnumDSSDataType DataType, CComVariant *pData, DSSDataFlag *pFlag);
    
    HRESULT GetInputParamType (Int32 nParamIndex, EnumDSSParameterType *pType);
    
    int Clear ();
    
    HRESULT IsNullProcessable (bool *pCanProcessNULL);
    
    // 3/21/2012 tehe
    int Init (EnumSimpleOperatorType iFunctionIndex);
    
    //ctang 2010-6-1
    HRESULT GetOutput(Int32 nSize, Int32 *nDataSize,  double * pData, DSSDataFlag * pFlag);
    
    HRESULT GetOutputType(EnumDSSParameterType * pType);
    
    HRESULT SetInputParam(Int32 nParamIndex, Int32 nSize, double * pData, DSSDataFlag * pFlag);    
    
    // jxie, 2010-9-9, support DirectCalculate for numeric types
    HRESULT DirectCalculate(Int32 nParam, Int32* ipSize, 
                        void** ipData, double* ipDivider, DSSDataFlag** ipFlags, VARIANT_BOOL* ipAllDataValid,
                        EnumDSSDataType* iType, vector<Int32, MBase::Allocator<Int32> > * ipvDataByGroup,
                        Int32 nResSize, double* opData, DSSDataFlag* opFlag, VARIANT_BOOL* opAllDataValid, 
                        EnumNullCheckingOption iNullCheckingOption);
    
    bool SupportDirectCalculate();
    
private:
    CComVariant *mpData;
    DSSDataFlag *mpInputFlag;
    DSSDataFlag *mpResultFlag;
    Int32 mnDataSize;
    Int32 mStatus;
    EnumDSSDataType mDataType;
    bool *mpResult;    
    //ytang 2008-06-17
    bool mTreatMathErrorAsNull;    
    //ctang 2010-6-1
    double* mpNumericInputData;    
    bool mfIsNumeric;    
};

#endif

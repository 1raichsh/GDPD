//
//  DSSSimpleOperatorGeneric.h
//  ReportServiceCore
//
//  Created by Yang Zhuo on 7/25/11.
//  Copyright 2011 Microstrategy. All rights reserved.
//

#ifndef DSSSIMPLEOPERATOR_H
#define DSSSIMPLEOPERATOR_H 1

#import "DSSGenericFunction.h"
#import "list"

class DSSSimpleOperatorGeneric : public DSSGenericFunction
{
public:
    DSSSimpleOperatorGeneric();
    ~DSSSimpleOperatorGeneric();
//    int Init(EnumDSSFunction Index);
//    EnumDSSFunction getOperatorType();
    virtual HRESULT setProperty(int Index, CComVariant *ipVal);
	HRESULT Calculate();
    HRESULT GetOutput(Int32 nSize, Int32 *nDataSize, double *pData, DSSDataFlag *pFlag);
    HRESULT GetOutputType(EnumDSSParameterType *pType);
    int Clear();
    HRESULT SetInputParam(Int32 nParamIndex, Int32 nSize, double *pData, DSSDataFlag *pFlag);
	HRESULT GetInputParamType(Int32 nParamIndex, EnumDSSParameterType *pType);
    HRESULT IsNullProcessable(bool *pCanProcessNull);
    virtual HRESULT DirectCalculate(Int32 nParam, Int32* ipSize, Int32** ipOffsets, 
                        void** ipData, double* ipDivider, DSSDataFlag** ipFlags, VARIANT_BOOL* ipAllDataValid,
                        EnumDSSDataType* iType, vector<Int32> * ipvDataByGroup,
                        Int32 nResSize, double* opData, DSSDataFlag* opFlag, VARIANT_BOOL* opAllDataValid,
                        EnumNullCheckingOption iNullCheckingOption);
    virtual bool SupportDirectCalculate();
private:
	bool *mpbResult;
    DSSDataFlag *mpResultFlag;
    std::list<bool*> mpValueList;
    std::list<DSSDataFlag*> mpFlagList;
    Int32 mnSize;
};

#endif

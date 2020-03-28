//
//	DSSWeightCovariance.h
//  ReportServiceCore
//
//  Create by xzhu on 07/01/2014
//  Copyright (c) 2014 MicroStratey, Inc. All rights reserved.

#ifndef CDSSWeightCovariance_h
#define CDSSWeightCovariance_h 1

#import "DSSGenericFunction.h"

class DSSWeightCovarianceFunction:public DSSGenericFunction
						
{
public:
	DSSWeightCovarianceFunction();

	~DSSWeightCovarianceFunction();

    HRESULT get_FunctionType (EnumDSSFunctionType *  pType);
    HRESULT setProperty (Int32 Index, CComVariant *pValue);

	HRESULT Calculate ();
    HRESULT SetInputParam (Int32 nParamIndex, Int32 nSize, double *pData, DSSData_Flags *pFlag);

    HRESULT GetOutput (Int32 nSize, 	// Input buffer size
                   Int32 *nDataSize, 	// return data size
                   double *pData, 	// Double array stores the result of function
                   DSSData_Flags *pFlag	// Output flags
                   );

    HRESULT GetOutputType (EnumDSSParameterType *pType);
    HRESULT GetInputParamType (Int32 nParamIndex, EnumDSSParameterType *pType);
    HRESULT IsNullProcessable (bool *pCanProcessNULL);
    int Clear ();

	int SetUseAsWeightStdevP(bool iUseAsWeightStdevP);

private:
	double  *mpxValues;
	double	*mpyValues;
	double	*mpWeights;
	DSSData_Flags* mpFlags;

	double  mResult;
	DSSData_Flags mResultFlag;

	Int32	mDataSize;

	bool	mbUseAsWeightCorr;
};


#endif

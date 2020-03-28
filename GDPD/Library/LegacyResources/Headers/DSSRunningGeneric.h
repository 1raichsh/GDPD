//
//  DSSRunningGeneric.h
//  ReportServiceCore
//
//  Created by Guanlin Shen on 09/14/99.
//  Copyright 1999 MicroStrategy, Inc. All rights reserved.
//

#ifndef RunningGeneric_h
#define RunningGeneric_h 1

#import "DSSGenericFunction.h"
#import "VariantCommonInclude.h"
#import "Base/Defines/StrongPtr.h"

class DSSRunningGeneric : public DSSGenericFunction
{
public:
    DSSRunningGeneric();
    
    ~DSSRunningGeneric();
    
    //	There is only one property for this function object. The
    //	possible values are :
    //	    DssRelationalOpen
    //	    DssRelationalCloseFloor
    //	    DssRelationalCloseCeiling
    //	    DssRelationalCloseRound
    virtual HRESULT setProperty (Int32 Index, CComVariant *pValue);
    
    //	This method is to accomplish the calculation.
    HRESULT Calculate ();
    
    //	This method is to set the input parameter.
    HRESULT SetInputParam (Int32 nParamIndex, Int32 nSize, double *pData, DSSDataFlag *pFlag);
    
    HRESULT GetOutput (Int32 nSize,         // Input buffer size
                   Int32 *nDataSize, 	// return data size
                   double *pData,       // Double array stores the result of function
                   DSSDataFlag *pFlag	// Output flags
                   );
    
    HRESULT GetOutputType (EnumDSSParameterType *pType);
    
    HRESULT GetInputParamType (Int32 nParamIndex, EnumDSSParameterType *pType);
    
    HRESULT IsNullProcessable (bool *pCanProcessNULL);
    
    int Clear ();
    
private:
    int  CalculateRunningSum();
    
    int  CalculateRunningAvg();
    
    HRESULT  CaculateRunnningStdev();
    
    //	Size of the input metric
    Int32 mDataSize;
    
    MBase::StrongArrayPtr<double> mpDataPtr;
    MBase::StrongArrayPtr<DSSDataFlag> mpDataFlagPtr;
    
    MBase::StrongArrayPtr<double> mpResultPtr;
    MBase::StrongArrayPtr<DSSDataFlag> mpResultFlagPtr;        
};

#endif

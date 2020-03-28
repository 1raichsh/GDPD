//
//  DSSExpWghRunningAvg.h
//  ReportServiceCore
//
//  Created by Jia Zhang on 7/27/11.
//  Copyright 2011 MicroStrategy, Inc. All rights reserved.
//

#ifndef ExpWghRunningAvg_h
#define ExpWghRunningAvg_h 1

#import "DSSGenericFunction.h"
#import "VariantCommonInclude.h"

class DSSExpWghRunningAvg : public DSSGenericFunction
{
public:
    DSSExpWghRunningAvg();
    
    ~DSSExpWghRunningAvg();
    
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
    HRESULT SetInputParam (Int32 nParamIndex, Int32 nSize, double *pData,  DSSDataFlag *pFlag);
    
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
    void ExpBackward (Int32 iVal);        
    Int32 mDataSize;    //	Size of the input metric         
    double *mpData;     //	hold the pointer to the input metric
     DSSDataFlag *mpDataFlag;
    
    //	The result of the calculation. The size should be same as mDataSize.
    double *mpResult;
    
    DSSDataFlag *mpResultFlag;
    double mRate;    
};

#endif

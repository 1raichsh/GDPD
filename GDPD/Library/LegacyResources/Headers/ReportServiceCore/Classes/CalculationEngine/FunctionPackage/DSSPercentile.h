//
//  DSSPercentile.h
//  ReportServiceCore
//
//  Created by Jia Zhang on 7/27/11.
//  Copyright 2011 MicroStrategy, Inc. All rights reserved.
//

#ifndef Percentile_h
#define Percentile_h 1

#include "DSSIndexFunction.h"

#import "VariantCommonInclude.h"

class DSSPercentile : public DSSIndexFunction
{
public:
    DSSPercentile();
    
    ~DSSPercentile();
    
    virtual HRESULT setProperty (Int32 Index, CComVariant *pValue);
    
    HRESULT Calculate ();
    
    HRESULT GetOutput (Int32 nSize, Int32 *nDataSize, double *pData, DSSDataFlag *pFlag);
    
    HRESULT IsNullProcessable (bool *pCanProcessNULL);
        
private:    
    bool mAsc;    
};

#endif

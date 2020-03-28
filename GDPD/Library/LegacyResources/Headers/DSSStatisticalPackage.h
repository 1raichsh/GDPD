//
//  DSSStatisticalPackage.h
//  ReportServiceCore
//
//  Created by He Tengfei on 3/8/12.
//  Copyright 2012 MicroStrategy, Inc. All rights reserved.
//
#ifndef CDSSStatisticalPackage_h
#define CDSSStatisticalPackage_h 1

#include "DSSFunctionPackage.h"

class DSSStatisticalPackage : public DSSFunctionPackage
{
public:
    DSSStatisticalPackage();
    ~DSSStatisticalPackage();
    
    HRESULT Count (int *opCount);
    
    HRESULT getCLSID (GUID *opCLSID);
    
    HRESULT getDescription (char **opDescription);
    
    HRESULT getName (char **opName);
    
    HRESULT getVersion (char **opVersion);
    
    DSSFunctionObject* Item(int iIndex);
};
#endif

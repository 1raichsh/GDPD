//
//  DSSFinancialPackage.h
//  ReportServiceCore
//
//  Created by He Tengfei on 2/22/12.
//  Copyright 2012 MicroStrategy, Inc. All rights reserved.
//

#ifndef DSSFinancialPackage_h
#define DSSFinancialPackage_h 1

#include "DSSFunctionPackage.h"

class DSSFunctionObject;

class DSSFinancialPackage: public DSSFunctionPackage
{
public:
    DSSFinancialPackage();
    ~DSSFinancialPackage();
    
    HRESULT Count (int *opCount);
    
    HRESULT getCLSID (GUID *opCLSID);
    
    HRESULT getDescription (char **opDescription);
    
    HRESULT getName (char **opName);
    
    HRESULT getVersion (char **opVersion);
    
    DSSFunctionObject* Item(int iIndex);

};
#endif

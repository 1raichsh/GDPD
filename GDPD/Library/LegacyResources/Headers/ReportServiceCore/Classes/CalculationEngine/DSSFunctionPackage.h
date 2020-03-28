//
//  DSSFunctionPackage.h
//  ReportServiceCore
//
//  Created by Jia Zhang on 9/9/11.
//  Copyright 2011 MicroStrategy, Inc. All rights reserved.
//

#ifndef FunctionPackage_h
#define FunctionPackage_h 1

#import "GUID.h"

class DSSFunctionObject;

class DSSFunctionPackage
{
public:
    DSSFunctionPackage();
    virtual ~DSSFunctionPackage();
    
    virtual HRESULT Count (int *opCount) = 0;

    virtual HRESULT getCLSID (GUID *opCLSID) = 0;
    
    virtual HRESULT getDescription (char **opDescription) = 0;
    
    virtual HRESULT getName (char **opName) = 0;
    
    virtual HRESULT getVersion (char **opVersion) = 0;
    
    virtual DSSFunctionObject * Item (int iIndex) = 0;
};

#endif

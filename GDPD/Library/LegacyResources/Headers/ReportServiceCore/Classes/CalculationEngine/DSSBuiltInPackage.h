//
//  DSSBuiltInPackage.h
//  ReportServiceCore
//
//  Created by Jia Zhang on 9/9/11.
//  Copyright 2011 MicroStrategy, Inc. All rights reserved.
//

#ifndef BuiltInPackage_h
#define BuiltInPackage_h 1

#import "DSSFunctionPackage.h"

class DSSFunctionObject;

class DSSBuiltInPackage : public DSSFunctionPackage
{
public:
    DSSBuiltInPackage();
    ~DSSBuiltInPackage();
    
    HRESULT Count (int *opCount);
    
    HRESULT getCLSID (GUID *opCLSID);
    
    HRESULT getDescription (char **opDescription);
    
    HRESULT getName (char **opName);
    
    HRESULT getVersion (char **opVersion);
    
    DSSFunctionObject* Item(int iIndex);
    
    static DSSFunctionObject* getFunctionByIndex(int iIndex);
    
};

#endif

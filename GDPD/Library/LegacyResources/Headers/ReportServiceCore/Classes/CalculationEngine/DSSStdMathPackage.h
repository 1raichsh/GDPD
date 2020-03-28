//
//  DSSStdMathPackage.h
//  ReportServiceCore
//
//  Created by He Tengfei on 2/21/12.
//  Copyright 2012 MicroStrategy, Inc.. All rights reserved.
//



#ifndef DSSStdMathPackage_h 
#define DSSStdMathPackage_h 1

#include "DSSFunctionPackage.h"

class DSSFunctionObject;

class DSSStdMathPackage : public DSSFunctionPackage
{
public:
    
    DSSStdMathPackage();
    
    ~DSSStdMathPackage();
      
    HRESULT Count (int *opCount);
    
    HRESULT getCLSID (GUID *opCLSID);
    
    HRESULT getDescription (char **opDescription);
    
    HRESULT getName (char **opName);
    
    HRESULT getVersion (char **opVersion);
    
    DSSFunctionObject* Item(int iIndex);
    
};

#endif

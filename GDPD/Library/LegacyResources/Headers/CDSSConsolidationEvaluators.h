//
//  CDSSConsolidationEvaluators.h
//  ReportServiceCore
//
//  Created by Liao Taimin on 4/17/13.
//  Copyright (c) 2013 MicroStrategy, Inc. All rights reserved.
//

#ifndef ReportServiceCore_CDSSConsolidationEvaluators_h
#define ReportServiceCore_CDSSConsolidationEvaluators_h

#include "DSSFunctionPackage.h"

#include <vector>

class DSSFunctionObject;
class DSSObjectContext;
class DSSFunctionServer;
class DSSTabularConsolidation;
class CDSSConsolidationEvaluator;

class CDSSConsolidationEvaluators : public DSSFunctionPackage
{    
public:
    CDSSConsolidationEvaluators();
    ~CDSSConsolidationEvaluators();
    
    
    virtual DSSFunctionObject * Item (int iIndex);

    virtual HRESULT Count(int *pCount);
    
    virtual HRESULT getCLSID(GUID *pCLSID);
    
    virtual HRESULT getDescription(char **pDescription);
    
    virtual HRESULT getName(char **pName);
    
    virtual HRESULT getVersion(char **pVersion);
    
    HRESULT init(DSSObjectContext* ipObjContext, DSSFunctionServer *pFunctionServer, DSSTabularConsolidation *pXTabConsolidation);
    
    int put_DynamicAggFunc(Int32 iFuncIndex);
    
    int put_NonAggFunc(Int32 iFuncIndex);    
    
    
private:

    std::vector<CDSSConsolidationEvaluator *> mvEvaluators;

    DSSTabularConsolidation *mpXTabConsolidation;

    DSSFunctionServer *mpFunctionServer;
};

#endif

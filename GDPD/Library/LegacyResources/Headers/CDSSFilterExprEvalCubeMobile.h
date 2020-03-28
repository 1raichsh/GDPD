//
//  CDSSFilterExprEvalCubeMobile.h
//  ReportServiceCore
//
//  Created by Lin, Weiwei on 3/12/19.
//  Copyright © 2019 MicroStrategy, Inc. All rights reserved.
//

#ifndef CDSSFilterExprEvalCubeMobile_h
#define CDSSFilterExprEvalCubeMobile_h

#include "CDSSFilterExprEval.h"
#include "DFCWObjectContext.h"
#include "DSSCalculationHelper.h"
#include "DFCWFunctionServer.h"
#include "DFCWReportInstance.h"
#include "DFCWCalculationPlan.h"
#include "DFCWSource.h"
#include "DFCWTemplate.h"
#include "DSSLevelResolver.h"
#include "DSSCalculationEvent.h"
#include "DFCWCalculationHelper.h"
#include "DFCDataConversion.h"
#include "DSSBigDecimalWrapper.h"
// weilin CDSSFilterExprEvalCubeMobile inherits from CDSSFilterExprEval. If we found any issue in the class, we should investigate server code CDSSFilterExprEvalCube/CDSSFilterExprEval first.
class CDSSFilterExprEvalCubeMobile : public CDSSFilterExprEval
{
public:
    CDSSFilterExprEvalCubeMobile(MBase::Buffer *ipBuffer,
                                 CDSSCube    *ipTargetCube,
                                 DSSFunctionServer *ipFuncServer,
                                 EventContext    *ipCntxt);
    ~CDSSFilterExprEvalCubeMobile();
protected:
    virtual HRESULT Init();
    //This function carries out arithmetic and logic calculation such as +,-,*,/, <, >
    virtual HRESULT EvaluateExpressionFunction(
                                               DFCWNode * ipNode,
                                               DFCWMetric *ipMetric,
                                               Int32 inSliceID,
                                               CDSSSliceID *ipSliceID,
                                               CDSSSliceID *opSliceID);
    
    //evalute EQUAL, AND, OR, NOT
    virtual HRESULT  EvaluateRelationFunction(
                                              DSSFunction_Type iFunction,
                                              Int32 inSliceID,
                                              CDSSSliceID *ipSliceID,
                                              CDSSSliceID *opSliceID);
    
    //Evaluate attribute element filter
    virtual HRESULT EvaluateElementFilter(
                                          Int32 iAttributeID,
                                          const FilterExpressionLeaf& iElement,
                                          CDSSSliceID * opFilterSliceID);
    
    // lweng 2014-7-24,
    // Evaluate DE element filter
    virtual HRESULT EvaluateDEElementFilter(
                                            Int32 iConsolidationID,
                                            const FilterExpressionLeaf& iElement,
                                            CDSSSliceID* opFilterSliceID);
    
    //convert a constant to an id of it
    virtual HRESULT GenerateConstantInput(
                                          const VARIANT &iConst,
                                          DSSDataType_Type iConstDataType,
                                          CDSSSliceID &oConstID);
    
    //converts metric DSS_ID into metric input integer id
    virtual HRESULT EvaluateMetric(
                                   METRIC_ID &iMetricID,
                                   CDSSSliceID  &oMetricID);
    
    //juzhang, 2013-11-24, metric me node's metric DSS_ID into metric input integer id
    virtual HRESULT  EvaluateMeNodeMetric(CDSSSliceID  &oMetricID);
    
    //Convert an attribute form that indentified by its node short cut to
    //a vector of integer attribute ids
    virtual HRESULT  GenerateAttributeFormInputs(
                                                 DFCWNodeFormShortcut * ipAttrFormShorcut,
                                                 std::vector<CDSSSliceID, MBase::Allocator<CDSSSliceID> > &oAttributeFormIDs);
    
    //Convert an attribute indentified by its GUID to the input id
    virtual HRESULT GenerateAttributeInput(
                                           const DSS_ID &iAttributeID,
                                           Int32 &oAttriuteID, bool* opConsolidation = NULL);
    
    //Convert extract information from attribute element object, including attribute id
    //element data type, element data length and element value.
    virtual HRESULT GenerateElementInputs(
                                          DFCWElement *ipElement,
                                          Int32 &oAttributeID,
                                          DSSDataType_Type * &opTypes,
                                          Int32 * &opcbDatas,
                                          unsigned char ** &oppDatas,
                                          DSSData_Flags * &pFlags);
    
    virtual HRESULT ApplyFiltertoDimty(Int32 nDimUnits,
                                       DSS_ID *pDimUnits,
                                       CDSSSliceID *pFilterSliceID,
                                       CDSSSliceID * pResultSliceID);
    
    virtual HRESULT EvaluateMetricFromOtherCube(
                                                CDSSCube* ipCube,
                                                DFCWGridIterator* ipGridIterator,
                                                DFCWSlicedGridWindow* ipWindow,
                                                DSS_ID iMetricID,
                                                CDSSSliceID* pSliceID);
    
    virtual HRESULT GenerateConstantFromGridRowInList(
                                                      DFCWNodeGridUnitShortcut* ipGridNode,
                                                      DFCWGridIterator* ipGridIterator,
                                                      DFCWSlicedGridWindow* ipSliceWindow,
                                                      Int32 iRow,
                                                      Int32 iCol,
                                                      Int32 &oAttributeUnit,
                                                      Int32 &oElemKey);
    
    virtual HRESULT GenerateConstantFromGridRow(
                                                DFCWNodeGridUnitShortcut* ipGridNode,
                                                DFCWGridIterator* ipGridIterator,
                                                DFCWSlicedGridWindow* ipSliceWindow,
                                                Int32 iRow,
                                                Int32 iCol,
                                                VARIANT* opValue);
    
    virtual HRESULT GenerateAttributeFormInputsFromOtherCube(
                                                             CDSSCube* ipCube,
                                                             DFCWNodeGridUnitShortcut* ipGridUnit,
                                                             CDSSTabularDataUnit* ipTabularUnit,
                                                             Int32 iUnitIndex,
                                                             Int32 iLocale,
                                                             CDSSSliceID* pSliceID);
    
    virtual HRESULT GenerateConstantInput(Int32 iUnit,
                                          Int32* ipUnit,
                                          char* ipData,
                                          Int32 iDataSize,
                                          EnumDSSDataType iDataType,
                                          DSSDataFlag iDataFlag,
                                          CDSSSliceID* pResultSliceID);
    
    virtual HRESULT GenerateCountAttributeInput(DFCWNodeGridUnitShortcut* ipGridUnit,
                                                CDSSSliceID* pSliceID);
private:
    CDSSCube    *mpSourceCube;
    CDSSCube    *mpTargetCube;
    CDSSTabularData *mpTabularData;
    DFCWCalculationPlan *mpCalculationPlan; ////source cube's calculation plan
    Int32 mCurLevel;
    Int32 mCurEvent;
    DFCWSource *mpSource;
    DFCWFunctionServer *mpFuncServer;
    DFCWReportInstance * mpReportInstance;
    DFCWTemplate * mpTemplate;
    EnumNullCheckingOption mNullCheckingOption;
    CDSSResolveLevel* mpResolveLevel;
    
    bool mfEvaluateThreshold;
    METRIC_ID *mpMeMetricID;
    CDSSMaskInfos* mpMaskInfo;
    MCESchema* mpSchema;
    
    Int32 mAEVersion;
    HRESULT hGenerateMetricSlice(const METRIC_ID  &iMetricID,
                                 CDSSSliceID *opSliceID);
};
#endif /* CDSSFilterExprEvalCubeMobile_h */

class DFCWString
{
public:
    
#ifdef SERVER_COM_OBJECT
    CComBSTR m_str;
#else
    std::string m_str;
#endif
    
    DFCWString()
    {
#ifdef SERVER_COM_OBJECT
        m_str = NULL;
#else
        m_str = "";
#endif
    }
    
    ~DFCWString()
    {
    }
    
    
    bool operator==(DFCWString str) const
    {
#ifdef SERVER_COM_OBJECT
        
        return (m_str == BSTR(str.m_str));
        
#else
        return m_str.compare(str.m_str) == 0;
#endif
    }
    
};

/*
 *  DSSSort.h
 *  DashboardViewer
 *
 *  Created by Luo Ming on 09-12-30.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SORT_H
#define SORT_H

#include "DSSTemplateAttribute.h"
#include <vector>
class DSSAxis;
class DSSSort : DSSSecondClassObject
{
private:
	EnumDSSSortType mSortType;
	bool mAscending;
	GUID mObjectID;
	EnumDSSObjectType mObjectType;
	GUID mFormID;
	int mBaseFormID;
	int mSubtotalIndex;
	int mSubtotalPosition;
	int mLocale;
	DSSBaseElementsProxy* mpElements;
    // weilin DE60559 2017/5/9 only used for sort manipulation on graph matrix
    int mAxisIndex;
    DSSAxis* mpAxis;
public:
	DSSSort();
	virtual ~DSSSort();
	DSSSort(DSSObjectContext* ipObjectContext);
	EnumDSSSortType getSortType();
	bool getAscending();
	GUID getObjectID();
	EnumDSSObjectType getObjectType();
	GUID getFormID();
	int getBaseFormID();
    int getFormIndex();
	int getSubtotalIndex();
	int getSubtotalPosition();
	DSSBaseElementsProxy* getElements();
	void setElements(DSSBaseElementsProxy* ipElements);
	int LoadDefnFromBinary(DSSBinaryDataReader* ipReader);

	void setSortType(EnumDSSSortType iSortType);
	void setAscending(bool iAscending);
	void setObjectID(GUID iID);
	void setSubtotalPosition(int iSubtotalPosition);
	void setFormID(GUID iFormID);
	void setBaseFormID(int iBaseFormID);
    
    int getLocale();
    void Duplicate(DSSSort* ipSort);

    int getAxisIndex() {
        return mAxisIndex;
    }
    void setAxisIndex(int iAxisIndex) {
        mAxisIndex = iAxisIndex;
    }

    void setObjectType(EnumDSSObjectType iObjType) {
        mObjectType = iObjType;
    }
    
    inline DSSAxis* getAxis() { return mpAxis; }
    void setAxis(DSSAxis* ipAxis);
};

#endif

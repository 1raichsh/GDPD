/*
 *  DSSRWDHelper.h
 *  DashboardViewer
 *
 *  Created by Xiaolong Wang on 2/4/10.
 *  Copyright 2010 MicroStrategy, Inc.. All rights reserved.
 *
 */

#import <vector>
#import "DSSrwdconstants.h"
#import "GUID.h"
#import "DiagnoseCxx.h"

using namespace std;

class DSSRWDHelper
{
public:
	void Dummy();

	//determine the value N in range [start, end), for which "val >= rvSortedList[N] && val <= rvSortedList[N + 1]" is true
	template<class T>
	static bool BinarySearch(T val, std::vector<T> &rvSortedList, int start, int end, int &orOffset);
	
};

template<class T>
bool DSSRWDHelper::BinarySearch(T val, std::vector<T> &rvSortedList, int start, int end, int &orOffset)
{
	if (start < 0 || start >= rvSortedList.size() || start > end)
		return false;
	
	int *lpList = &rvSortedList[0];
	int left = start;
	int right = end;
	while(left < right)
	{
		int mid = (right - left) / 2 + left;
		
		if (val >= lpList[mid] && val <= lpList[mid + 1])
		{
			orOffset = (val == lpList[mid + 1]) ? mid + 1 : mid;
			return true;
		}
		else if (val < lpList[mid])
			right = mid - 1;
		else if (val > lpList[mid + 1])
			left = mid + 1;
	}//end of while (left < right)
	
	orOffset = right;	//left >= right
	
	if (val < lpList[orOffset] || val > lpList[orOffset + 1])
	{
		_ASSERT(false);
		return false;
	}
	
	return true;
}

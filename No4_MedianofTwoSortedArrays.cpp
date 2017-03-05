// No4_MedianofTwoSortedArrays.cpp
// 求两个有序数组并集的中位数
/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
 */
#include <iostream>
#include <vector>
using namespace std;

void printintvct(const vector<int> &vct)
{
	for (int i = 0; i < vct.size(); i++)
    {
    	cout << vct[i] << " ";
    }

    cout << endl;
}

class Solution {
public:
    static double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2) {
    	printintvct(nums1);
    	printintvct(nums2);

    	if (nums1.size() == 0)
    	{
    		return 0;
    	}
    	else if (nums2.size() == 0 && nums1.size() == 1)
    	{
    		return nums1[0];
    	}

    	vector<int> vcttmp = nums1;
    	int icur = 0;

    	for (int i = 0; i < nums2.size(); i++)
    	{
			for (; icur < vcttmp.size(); icur++)
    		{
    			if (nums2[i] < vcttmp[icur])
    			{
    				vcttmp.insert(vcttmp.begin() + icur, nums2[i]);
    				icur = icur + 1;
    				break;
    			}
    		}

    		if (vcttmp.size() == icur)
    		{
    			vcttmp.push_back(nums2[i]);
    		}
    	}

    	printintvct(vcttmp);

    	int itotal = vcttmp.size();
    	int ihalf = itotal/2;

    	if (itotal % 2 == 0)
    	{
			return ((float)(vcttmp[ihalf - 1] + vcttmp[ihalf])) / 2;    		
    	}
    	else
    	{
    		return vcttmp[itotal / 2];
    	}
	}
    
    static double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
 		if (nums1.size() >= nums2.size()) {
 			return findMedianSortedArrays2(nums1, nums2);
 		} else {
 			return findMedianSortedArrays2(nums2, nums1);
 		}
    }
};



int main(int iargc, char **argv)
{
	vector<int> t1 = {1, 2};
	vector<int> t2 = {1, 1};
	cout << Solution::findMedianSortedArrays(t1, t2) << endl;
	return 0;
}








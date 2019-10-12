//--------------------------------------------------------------------
//53. Maximum Subarray
//Easy
//
//Given an integer array nums, find the contiguous subarray(containing at least one number) which has the largest sum and return its sum.
//
//Example:
//
//Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4],
//	Output : 6
//	Explanation : [4, -1, 2, 1] has the largest sum = 6.
//	Follow up :
//
//	   If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
//--------------------------------------------------------------------

#include <string>
#include <vector>




class Solution {


public:
	int maxSubArray(std::vector<int>& nums) {
		int headIdx = -1;
		int tailIdx = -1;
		int count = static_cast<int>(nums.size());
		int maxResult = 0;
		int currentResult = 0;
		for(int i = 0; i < count; i++)
		{
			currentResult += nums[i];
			headIdx = i;
			if(tailIdx==-1)
				tailIdx = i;

			if(headIdx==tailIdx) 
			{//��һ��λ��
				maxResult = currentResult;
				continue;
			}

			if(maxResult < currentResult) maxResult = currentResult;

			int tailNumber = nums[tailIdx];
			if(tailNumber < 0)
			{
				tailIdx++;
				currentResult -= tailNumber;
				if(maxResult < currentResult) maxResult = currentResult;
			}

			int headNumber = nums[headIdx];
			if(headNumber < 0 && currentResult < 0)//���headһ���ԾͰ�֮ǰ���������˸�������ôhead����̫���ˣ�֮ǰ�����в����ܼӳ����������ֵ��ֱ�Ӱ�tail����������¿�ʼ����
			{
				tailIdx = i;
				currentResult = nums[i];
				continue;
			}
		}

		return maxResult;
	}


};



//int main()
//{
//	Solution so;
//	std::vector<int> a={1,2,-4,-5,6,3,6,-1,5,9,-6};
//	
//
//	int result = so.maxSubArray(a);
//
//	return 0;
//
//}



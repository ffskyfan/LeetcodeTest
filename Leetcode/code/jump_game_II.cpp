//--------------------------------------------------------------------
//45. Jump Game II
//Hard
//Given an array of non - negative integers nums, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//You can assume that you can always reach the last index.
//
//
//
//Example 1:
//
//Input: nums = [2, 3, 1, 1, 4]
//Output : 2
//Explanation : The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
//Example 2 :
//
//	Input : nums = [2, 3, 0, 1, 4]
//	Output : 2
//
//
//	Constraints :
//
//	1 <= nums.length <= 3 * 104
//	0 <= nums[i] <= 105
//--------------------------------------------------------------------

#include <vector>
#include <algorithm>

using namespace std;

class Solution {



public:
    int jump(vector<int>& nums) {

		int count = static_cast<int>(nums.size());
		if(count<=1) return 0;

		int idx = 0;
		int result = 0;
		for(;;)
		{ 
			int furthestIdx = 0;
			int furthestDistance = 0;
			int number = nums[idx];

			if(idx + number >= count - 1) 
			{
				result++;
				break;
			}

			if(number == 1)
			{
				idx++;
			}
			else
			{
				for(int i = 1; i <= number && idx + i < count; i++)
				{
					int currentIdx = idx + i;
					int numberEx = nums[currentIdx];
					int distance = currentIdx + numberEx;
					if(distance > furthestDistance)
					{
						furthestIdx = currentIdx;
						furthestDistance = distance;
					}
				}
				idx = furthestIdx;
			}

			result++;
		}
			
		return result;
    }
};


//�ⷨ����ͷ��ʼ���ҵ�ǰ������Ӧ�����֣���������ӵ�ǰ������ʼ�����϶�Ӧ���ֺ���Զ�����ߵ�������� {3,4,5,2,1,1,1} ,��idxΪ0��ʱ��
//     ������������������������idxΪ1ʱ�����ߵ� 1+4=5, idxΪ2ʱ�����ߵ�2+5=7��idxΪ3ʱ�����ߵ� 3+2=5��������Զ��idxΪ2��ʱ�����Ծ�����2��Ȼ���������Ĺ��̣�ֱ���ߵ����Ϊֹ��


//int main()
//{
//	//vector<int> candidates = { 5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5 };
//	//vector<int> candidates = { 1,2,3 };
//	vector<int> candidates = { 2,3,1,1,4 };
//
//	Solution so;
//	int result = so.jump(candidates);
//
//	return 0;
//
//}



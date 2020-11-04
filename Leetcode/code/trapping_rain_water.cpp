//-------------------------------------------------------------------------
//42. Trapping Rain Water
//Hard
//Given n non - negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
//
//
//
//Example 1:
//https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png
//
//
//Input: height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
//Output : 6
//Explanation : The above elevation map(black section) is represented by array[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1].In this case, 6 units of rain water(blue section) are being trapped.
//Example 2:
//
//Input: height = [4, 2, 0, 3, 2, 5]
//Output : 9
//
//
//Constraints :
//
//	n == height.length
//	0 <= n <= 3 * 104
//	0 <= height[i] <= 105
//---------------------------------------------------------------------------


#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

		int count = height.size();
		if(count<=2) return 0;

		int result = 0;
		int uncertaintyResult = 0;

		bool isHeadAdd = true;

		bool isFirst = true;
		int maxHeight = 0;
		int trapHeight = 0;

		for(int i = -1, j = count - 1; i < count && j >= 0 && i < j; )
		{
			if(isHeadAdd) i++;
			else j--;

			if(height[i]==0) continue;

			if(height[j] == 0) {
				if(isHeadAdd)
				{
					isHeadAdd = false;
				}
				continue;
			}

			int h = 0;
			if(isHeadAdd) { h = height[i]; }
			else { h = height[j]; }

			if(isFirst == false && h < trapHeight)
			{
				uncertaintyResult -= h;
			}
			else
			{
				if(isFirst == false)
				{
					uncertaintyResult -= trapHeight * (j - i);
					result += uncertaintyResult;
				}
				else
				{
					isFirst = false;
				}

				maxHeight = max(height[i], height[j]);
				trapHeight = min(height[i], height[j]);

				int space = j - i - 1;
				uncertaintyResult = trapHeight * space;

				if(height[i] <= height[j]) isHeadAdd = true;
				else isHeadAdd = false;

			}

			
		}

        return result;

    }
};

//�ⷨ�����������߿�ʼ�ҵ���Ϊ0�ĸ߶ȣ�ֻ�����߶��в�Ϊ0�ģ����ܱ�֤Χ���ռ䣬���ܽ�ˮ��
//֮���ҵ��߶ȱȽϵ͵�һ�ߣ���ΪA��������ʼ�������м��ң�����¸߶�X����A�ͣ��Ǿͼ�ȥ����Ϊռ����ˮ��λ�ã�����ߣ��ǾͰ�A��XΧ�����Ŀռ�ӵ�����ϣ�Ȼ���X�����µ�ǽ���ظ�����Ĺ��̡�


//int main()
//{
//	Solution so;
//	vector<int> x = { 6,0,1 };
//	int result = so.trap(x);
//
//	return 0;
//
//}
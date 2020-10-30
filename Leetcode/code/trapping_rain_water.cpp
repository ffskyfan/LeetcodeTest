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

		int result = 0;
		int uncertaintyResult = 0;

		int backIdx = 0;
		int backHeight = height[0];
		for(int i = 1; i < count; i++)
		{
			if(height[i] >= backHeight)
			{
				//result += i - backIdx - 1;
				//backIdx = i;
			}
			else 
			{
				uncertaintyResult += backHeight - height[i];


			}
		}

        return result;

    }
};



int main()
{
	Solution so;
	vector<int> x = { 4,2,0,3,2,5 };
	int result = so.trap(x);

	return 0;

}
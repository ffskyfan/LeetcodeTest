//--------------------------------------------------------------------
//11. Container With Most Water
//Medium
//Given n non - negative integers a1, a2, ..., an, where each represents a point at coordinate(i, ai).n vertical lines are drawn such that the two endpoints of line i is at(i, ai) and (i, 0).Find two lines, which together with x - axis forms a container, such that the container contains the most water.
//
//Note: You may not slant the container and n is at least 2.
//
//
//
//
//
//	The above vertical lines are represented by array[1, 8, 6, 2, 5, 4, 8, 3, 7].In this case, the max area of water(blue section) the container can contain is 49.
//
//
//
//	Example:
//
//	Input: [1, 8, 6, 2, 5, 4, 8, 3, 7]
//		Output : 49
//--------------------------------------------------------------------

#include <vector>
#include <algorithm>


class Solution {
public:
	int maxArea(std::vector<int>& height) {
		int count = static_cast<int>(height.size());
		if(count < 2) return 0;

		int result = 0;
		for(int i = 0; i < count; i++)
		{
			int iHeight = height[i];
			if(i != 0)
			{ 
				int maxPossibleHeight = iHeight * (count - i - 1);
				if(maxPossibleHeight < result) continue;
			}

			for(int j = i + 1; j < count; j++)
			{
				int jHeight = height[j];
				int minHeight = iHeight<jHeight?iHeight:jHeight;

				int area = minHeight*(j-i);
				if(area>result)
				{
					result = area;
				}

			}
		}

		return result;

	}
};




//int main()
//{
//
//	Solution so;
//	int result = so.countPrimes(10);
//
//	return 0;
//
//}



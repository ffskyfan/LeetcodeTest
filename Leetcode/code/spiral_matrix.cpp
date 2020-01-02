//--------------------------------------------------------------------
//54. Spiral Matrix
//Medium
//Given a matrix of m x n elements(m rows, n columns), return all elements of the matrix in spiral order.
//
//Example 1:
//
//Input:
//[
//	[1, 2, 3],
//	[4, 5, 6],
//	[7, 8, 9]
//]
//Output : [1, 2, 3, 6, 9, 8, 7, 4, 5]
//	Example 2 :
//
//	Input :
//	[
//		[1, 2, 3, 4],
//		[5, 6, 7, 8],
//		[9, 10, 11, 12]
//	]
//		 Output : [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
//--------------------------------------------------------------------

#include <string>
#include <vector>



using namespace std;


class Solution {
public:

	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		int rowCount = static_cast<int>(matrix.size());
		if(rowCount == 0) return result;

		bool isHorizontal = true;
		int columnCount = static_cast<int>(matrix[0].size());

		result.reserve(rowCount*columnCount);

		int top = 0;
		int bottom = rowCount-1;
		int left = 0;
		int right = columnCount-1;

		int j = top;
		int i = left;
		bool isPositiveDirection = true;
		bool isSkip = false;
		for(;;)
		{
			if(isSkip==false) result.push_back(matrix[j][i]);
			else isSkip = false;

			if(left == right && i == left && top == bottom && j == top) break;

			if(isHorizontal)
			{
				if(isPositiveDirection)
				{
					if(i == right)
					{
						isHorizontal = false;
						top++;
						isSkip = true;
					}
					else
					{
						i++;
					}
				}
				else
				{
					if(i == left)
					{
						isHorizontal = false;
						bottom--;
						isSkip = true;
					}
					else
					{
						i--;
					}
				}
			}
			else
			{
				if(isPositiveDirection)
				{
					if(j == bottom)
					{
						isHorizontal = true;
						isPositiveDirection = false;
						right--;
						isSkip = true;
					}
					else
					{
						j++;
					}
				}
				else
				{
					if(j == top)
					{
						isHorizontal = true;
						isPositiveDirection = true;
						left++;
						isSkip = true;
					}
					else
					{
						j--;
					}
				}

			}


		}

		return result;

	}
	

};



//int main()
//{
//	Solution so;
//	std::vector<int> nums = {1,2,4,3,5,3,4,3,4,5,3,4,7};
//
//	int result = so.removeElement(nums, 3);
//
//	return 0;
//
//}



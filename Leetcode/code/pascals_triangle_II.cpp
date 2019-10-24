//--------------------------------------------------------------------
//119. Pascal's Triangle II
//Easy
//
//Given a non - negative index k where k �� 33, return the kth index row of the Pascal's triangle.
//
//Note that the row index starts from 0.
//
//
//In Pascal's triangle, each number is the sum of the two numbers directly above it.
//
//Example:
//
//Input: 3
//	Output : [1, 3, 3, 1]
//	Follow up :
//
//	   Could you optimize your algorithm to use only O(k) extra space ?
//--------------------------------------------------------------------

#include <string>
#include <vector>




class Solution {

public:
	std::vector<int> getRow(int rowIndex) {

		int rowCount = rowIndex+1;
		std::vector<int> result;
		result.resize(rowCount, 1);
		int temp[2] = { 1,1 };
		for(int i = 2; i < rowCount; i++)
		{
			temp[0] = 1;
			temp[1] = 1;
			for(int j = 1; j < i; j++)
			{
				temp[0] = temp[1];
				temp[1] = result[j];

				result[j] = temp[0] + temp[1];
			}
		}

		return result;

	}
};



//int main()
//{
//	Solution so;
//	
//
//	std::vector<int> result = so.getRow(6);
//
//	return 0;
//
//}


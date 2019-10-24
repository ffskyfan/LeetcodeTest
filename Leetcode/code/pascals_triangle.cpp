//--------------------------------------------------------------------
//118. Pascal's Triangle
//Easy
//Given a non - negative integer numRows, generate the first numRows of Pascal's triangle.
//
//
//In Pascal's triangle, each number is the sum of the two numbers directly above it.
//
//Example:
//
//Input: 5
//	Output :
//	[
//		  [1],
//		 [1, 1],
//	    [1, 2, 1],
//	   [1, 3, 3, 1],
//	  [1, 4, 6, 4, 1]
//	]
//--------------------------------------------------------------------

#include <string>
#include <vector>




class Solution {

public:
	std::vector<std::vector<int>> generate(int numRows) {

		std::vector<std::vector<int>> result;
		for(int i = 0; i < numRows; i++)
		{
			std::vector<int> row;
			int size = i+1;
			row.resize(size,1);

			if(i > 1)
			{
				const std::vector<int>& lastRow = result[i-1];
				for(int j = 1; j < i; j++)
				{
					row[j] = lastRow[j-1] + lastRow[j];
				}
			}

			result.push_back(row);
		}

		return result;

	}
};



//int main()
//{
//	Solution so;
//	
//
//	std::vector<std::vector<int>> result = so.generate(6);
//
//	return 0;
//
//}



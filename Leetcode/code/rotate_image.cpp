//--------------------------------------------------------------------
//48. Rotate Image
//Medium
//You are given an n x n 2D matrix representing an image.
//
//Rotate the image by 90 degrees(clockwise).
//
//Note:
//
//You have to rotate the image in - place, which means you have to modify the input 2D matrix directly.DO NOT allocate another 2D matrix and do the rotation.
//
//Example 1 :
//
//	Given input matrix =
//	[
//		[1, 2, 3],
//		[4, 5, 6],
//		[7, 8, 9]
//	],
//
//	rotate the input matrix in - place such that it becomes :
//	[
//		[7, 4, 1],
//		[8, 5, 2],
//		[9, 6, 3]
//	]
//	Example 2:
//
//	Given input matrix =
//		[
//			[5, 1, 9, 11],
//			[2, 4, 8, 10],
//			[13, 3, 6, 7],
//			[15, 14, 12, 16]
//		],
//
//		rotate the input matrix in - place such that it becomes :
//		[
//			[15, 13, 2, 5],
//			[14, 3, 4, 1],
//			[12, 6, 8, 9],
//			[16, 7, 10, 11]
//		]
//--------------------------------------------------------------------

#include <string>
#include <vector>


using namespace std;


class Solution {

public:
	void rotate(vector<vector<int>>& matrix) {

		int end = static_cast<int>(matrix.size())-1;
		int temp = 0;

		for(int j = end; j > 0; j--)
		{
			for(int i = end-j; i < j; i++)
			{
				int m = end - i;
				int n = end - j;

				temp = matrix[i][n];
				matrix[i][n] = matrix[j][i];

				matrix[j][i] = temp;
				temp = matrix[n][m];
				matrix[n][m] = matrix[j][i];

				matrix[j][i] = temp;
				temp = matrix[m][j];
				matrix[m][j] = matrix[j][i];

				matrix[j][i] = temp;
			}
		}

	}

};




//int main()
//{
//	Solution so;
//	std::vector<int> a = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27 };
//	
//
//	so.rotate(a,38);
//
//	return 0;
//
//}



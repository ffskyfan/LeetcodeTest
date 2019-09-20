//--------------------------------------------------------------------
//1037. Valid Boomerang
//Easy
//
//A boomerang is a set of 3 points that are all distinct and not in a straight line.
//
//Given a list of three points in the plane, return whether these points are a boomerang.
//
//
//
//Example 1:
//
//Input: [[1, 1], [2, 3], [3, 2]]
//	Output : true
//	Example 2 :
//
//	Input : [[1, 1], [2, 2], [3, 3]]
//	Output : false
//
//
//	Note :
//
//	points.length == 3
//	points[i].length == 2
//	0 <= points[i][j] <= 100

//--------------------------------------------------------------------

#include <string>
#include <vector>




class Solution {



public:
	bool isBoomerang(std::vector<std::vector<int>>& points) {

		const std::vector<int>& a = points[0];
		const std::vector<int>& b = points[1];
		const std::vector<int>& c = points[2];

		int subX = a[0] - b[0];
		int subY = a[1] - b[1];

		if(subX ==0 && subY ==0) return false;

		if(subX == 0)
		{
			if(c[0] == a[0]) return false;
			else return true;
		}

		if(subY == 0)
		{
			if(c[1] == a[1]) return false;
			else return true;
		}

		int tX = (c[0] - a[0]) / subX;
		int tY = (c[1] - a[1]) / subY;
		int dX = (c[0] - a[0]) % subX;
		int dY = (c[1] - a[1]) % subY;
		if(tX == tY && dX == 0 && dX == dY)
		{
				return false;
		}


		return true;
	}

	

};



//int main()
//{
//	Solution so;
//	std::vector<std::vector<int>> points;
//	std::vector<int> pointA;
//	pointA.push_back(0);
//	pointA.push_back(0);
//	std::vector<int> pointB;
//	pointB.push_back(2);
//	pointB.push_back(2);
//	std::vector<int> pointC;
//	pointC.push_back(1);
//	pointC.push_back(0);
//
//	points.push_back(pointA);
//	points.push_back(pointB);
//	points.push_back(pointC);
//
//	bool result = so.isBoomerang(points);
//
//	return 0;
//
//}



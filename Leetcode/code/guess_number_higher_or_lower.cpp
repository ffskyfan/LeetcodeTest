//--------------------------------------------------------------------
//374. Guess Number Higher or Lower
//Easy
//We are playing the Guess Game.The game is as follows :
//
//I pick a number from 1 to n.You have to guess which number I picked.
//
//Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.
//
//You call a pre - defined API int guess(int num), which returns 3 possible results :
//
//-1 : The number I picked is lower than your guess(i.e.pick < num).
//	1 : The number I picked is higher than your guess(i.e.pick > num).
//	0 : The number I picked is equal to your guess(i.e.pick == num).
//	Return the number that I picked.
//
//
//
//	Example 1 :
//
//	Input : n = 10, pick = 6
//	Output : 6
//	Example 2 :
//
//	Input : n = 1, pick = 1
//	Output : 1
//	Example 3 :
//
//	Input : n = 2, pick = 1
//	Output : 1
//	Example 4 :
//
//	Input : n = 2, pick = 2
//	Output : 2
//
//
//	Constraints :
//
//	1 <= n <= 231 - 1
//	1 <= pick <= n
//--------------------------------------------------------------------

#include <string>
#include <vector>


using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num)
{
	return 0;
}

class Solution {



public:
	int guessNumber(int n) {

		int begin = 1;
		int end = n;
		int mid = 0;
		for(;begin <= end;)
		{
			mid = begin + ((end - begin) / 2);
			if(guess(mid) == 0)
			{
				break;
			}
			else if(guess(mid) == -1)
			{
				end = mid-1;
			}
			else
			{
				begin = mid+1;
			}
		}

		return mid;

	}

};

//解法：简单的二分查找，先找中间的数，如果大了我就往更小的地方找，如果小了，我就往更大的地方找
//一直类推就可以找到了。


//int main()
//{
//	Solution so;
//	std::vector<int> nums = {1,2,2};
//
//	std::vector<int> result = so.searchRange(nums,2);
//
//	return 0;
//
//}



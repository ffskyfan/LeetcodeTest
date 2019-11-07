//--------------------------------------------------------------------
//204. Count Primes
//Easy
//Count the number of prime numbers less than a non - negative number, n.
//
//Example:
//
//Input: 10
//	Output : 4
//	Explanation : There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
//--------------------------------------------------------------------

#include <vector>


class Solution {
public:
	int countPrimes(int n) {
		if(n==0||n==1) return 0;

		std::vector<int> nums;
		nums.resize(n);
		for(int i = 0; i < n; i++)
		{
			nums[i] = i;
		}

		int result = 0;
		for(int i = 2; i < n; i++)
		{
			if(nums[i]==0) continue;

			for(int j = i+nums[i]; j < n; j+=nums[i])
			{
				nums[j] = 0;
			}
			result++;
		}

		return result;
	}
};


//使用 埃拉托斯特尼筛法， 第一个质数是2，用2除以后面每个数，删除掉这些能被2整除的数，
//然后找下一个数，3，用3除以后面的每个数，删掉这些被3整除的数,之后下查找下一个数，因为4已经被删除了，找到5，继续同样的操作，就找到所有的质数。


//int main()
//{
//
//	Solution so;
//	int result = so.countPrimes(10);
//
//	return 0;
//
//}



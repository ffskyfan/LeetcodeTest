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


//ʹ�� ������˹����ɸ���� ��һ��������2����2���Ժ���ÿ������ɾ������Щ�ܱ�2����������
//Ȼ������һ������3����3���Ժ����ÿ������ɾ����Щ��3��������,֮���²�����һ��������Ϊ4�Ѿ���ɾ���ˣ��ҵ�5������ͬ���Ĳ��������ҵ����е�������


//int main()
//{
//
//	Solution so;
//	int result = so.countPrimes(10);
//
//	return 0;
//
//}



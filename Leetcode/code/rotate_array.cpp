//--------------------------------------------------------------------
//189. Rotate Array
//Easy
//Given an array, rotate the array to the right by k steps, where k is non - negative.
//
//Example 1:
//
//Input: [1, 2, 3, 4, 5, 6, 7] and k = 3
//	Output : [5, 6, 7, 1, 2, 3, 4]
//	Explanation :
//	rotate 1 steps to the right : [7, 1, 2, 3, 4, 5, 6]
//	rotate 2 steps to the right : [6, 7, 1, 2, 3, 4, 5]
//	rotate 3 steps to the right : [5, 6, 7, 1, 2, 3, 4]
//	Example 2 :
//
//	Input : [-1, -100, 3, 99] and k = 2
//	Output : [3, 99, -1, -100]
//	Explanation :
//	rotate 1 steps to the right : [99, -1, -100, 3]
//	rotate 2 steps to the right : [3, 99, -1, -100]
//	Note :
//
//	Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
//	Could you do it in - place with O(1) extra space ?
//--------------------------------------------------------------------

#include <string>
#include <vector>




class Solution {


	void rotateOnCycle(std::vector<int>& nums, int count, int k, int idx) {
		int i = idx;
		int temp = nums[i];
		do
		{
			int newPos = i + k;
			if(newPos >= count)
			{
				newPos -= count;
			}

			int inerTemp = nums[newPos];
			nums[newPos] = temp;
			temp = inerTemp;

			i = newPos;

		} while(i != idx);
	}


public:
	void rotate(std::vector<int>& nums, int k) {
		int count = static_cast<int>(nums.size());
		if(count <= 1 || k == 0) return;
		if(k > count) k = k % count;

		int end = count;
		int endk = k;
		while(endk != 0)
		{
			int r = endk;
			endk = end % endk;
			end = r;
		}

		for(int i = 0; i < end; i++)
		{
			rotateOnCycle(nums, count, k, i);
		}


	}

};


//O(n)情况的解法，通过归纳法得到的一个规律
//如果要滚动数组X位，那么可以从0位开始每隔X位把后面的数据放入前面X位里，以此循环
//比如6个元素的数组，滚动4位，那么最开始0位放入4位，4位放入2位(4+4=8,8超出数组大小，回滚一下，8-6=2)，2位放入0位((2+4=6,6超出数组大小，回滚一下，6-6=0))
//这时候我们发现操作已经重复了，但是1位还没有放过，所以从1位开始再来一次 1位放入5位，5位放入3位，3位放入1位。又开始循环，但是所有的数都放好了。
//也就是两次就可以了，那这个两次是怎么算出来的呢？实际上是6和4的最大公约数。代码里通过辗转相除法获得。


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



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


//O(n)����Ľⷨ��ͨ�����ɷ��õ���һ������
//���Ҫ��������Xλ����ô���Դ�0λ��ʼÿ��Xλ�Ѻ�������ݷ���ǰ��Xλ��Դ�ѭ��
//����6��Ԫ�ص����飬����4λ����ô�ʼ0λ����4λ��4λ����2λ(4+4=8,8���������С���ع�һ�£�8-6=2)��2λ����0λ((2+4=6,6���������С���ع�һ�£�6-6=0))
//��ʱ�����Ƿ��ֲ����Ѿ��ظ��ˣ�����1λ��û�зŹ������Դ�1λ��ʼ����һ�� 1λ����5λ��5λ����3λ��3λ����1λ���ֿ�ʼѭ�����������е������ź��ˡ�
//Ҳ�������ξͿ����ˣ��������������ô��������أ�ʵ������6��4�����Լ����������ͨ��շת�������á�


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



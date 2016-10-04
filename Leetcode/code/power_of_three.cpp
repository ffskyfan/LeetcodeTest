
//--------------------------------------------------------------------
//
//326. Power of Three
//Given an integer, write a function to determine if it is a power of three.
//
//Follow up:
//Could you do it without using any loop / recursion?
//--------------------------------------------------------------------


class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n <= 0) return false;

		for (; n >= 9;) {
			if (n % 3 != 0) return false;
			n = n / 3;
		}

		if (n == 3 || n==1) {
			return true;
		}
		else {
			return false;
		}
        
		//���ﻹ��һ���ⷨ�������ҵ�int������3��������֮���nȡ�࣬�������Ϊ0���Ǿ�����3Ϊ�ݵ��������������õ�ѭ��
    }
};


//int main()
//{
//	Solution so;
//	bool result = so.isPowerOfThree(19684);
//	//string result = so.convert("PAYPALISHIRING", 3);
//
//	return 0;
//
//}



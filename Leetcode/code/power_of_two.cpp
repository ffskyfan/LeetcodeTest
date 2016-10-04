//--------------------------------------------------------------------
//
//231. Power of Two
//Given an integer, write a function to determine if it is a power of two.
//--------------------------------------------------------------------


class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0) return false;
		int mask = 1;
		int num_of_one = 0;
		for (int i = 0; i < 32; i++) {
			mask = 1 << i;

			int bit = mask&n;
			if (bit > 0) {
				num_of_one++;
			}

			if (num_of_one > 1) return false;
		}

		return true;
    }
};


//int main()
//{
//	Solution so;
//	bool result = so.isPowerOfTwo(5);
//	//string result = so.convert("PAYPALISHIRING", 3);
//
//	return 0;
//
//}



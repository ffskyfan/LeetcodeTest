/*-----------------------------------------------------------------
//371. Sum of Two Integers 
//
//Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
//
//Example:
//Given a = 1 and b = 2, return 3.
//
------------------------------------------------------------------*/

#include <math.h>


class Solution {
public:
	int getSum(int a, int b) {

		int result = 0;
		int oc = 0;
		for (int i = 0; i < 32; i++) {
			
			int mask = pow(2, i);
			int a_bit_value = a&mask;
			int b_bit_value = b&mask;

			int bit_half_sum = a_bit_value^b_bit_value;
			int bit_half_oc = a_bit_value&b_bit_value;

			int bit_sum = bit_half_sum^oc;
			oc = bit_half_oc | (bit_half_sum&oc);

			oc = oc << 1;

			result = result | bit_sum;
		}

		return result;
	}
};

//int main()
//{
//	Solution so;
//	int result = so.getSum(2,3);
//	//string result = so.convert("PAYPALISHIRING", 3);
//
//	return 0;
//
//}
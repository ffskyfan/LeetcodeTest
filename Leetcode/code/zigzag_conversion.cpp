
#include <string>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows <= 1) return s;

		int length = (int)s.length();
		int mid_col_num = numRows - 2;
		int base_row = length / (numRows + mid_col_num);
		int step_length = numRows + mid_col_num;

		string result;
		result.reserve(length);
		for (int x = 0; x < numRows ; x++) {

			for (int y = 0; y <= base_row; y++) {
				int idx = y * step_length + x;
				if (idx >= length)continue;
				result.push_back(s.at(idx));

				if (x != 0 && x != numRows - 1) {
					int idx2 = y*step_length + (step_length - x);
					if (idx2 >= length)continue;
					result.push_back(s.at(idx2));
				}
			}
		}
		
		return result;
	}
};


//int main()
//{
//	Solution so;
//	string result = so.convert("ABCDE",4);
//	//string result = so.convert("PAYPALISHIRING", 3);
//
//	return 0;
//
//}
/*-----------------------------------------------------------------
//344. Reverse String
//
//Write a function that takes a string as input and returns the string reversed.
//
//Example:
//Given s = "hello", return "olleh".
------------------------------------------------------------------*/

#include <string>

using namespace std;

class Solution {
public:
    string reverseString(string s) {

		string::iterator it_head = s.begin();
		string::iterator it_tail = --s.end();
        
		char temp = ' ';
		for (;  it_head < it_tail; it_head++, it_tail--) {
			temp = *it_head;
			*it_head = *it_tail;
			*it_tail = temp;
		}

		return s;
    }
};


//int main()
//{
//	Solution so;
//	string result = so.reverseString("ABCDE");
//	//string result = so.convert("PAYPALISHIRING", 3);
//
//	return 0;
//
//}
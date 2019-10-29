//--------------------------------------------------------------------
//434. Number of Segments in a String
//Easy
//Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non - space characters.
//
//Please note that the string does not contain any non - printable characters.
//
//Example:
//
//Input: "Hello, my name is John"
//	Output : 5
//--------------------------------------------------------------------

#include <string>
#include <vector>




class Solution {



public:
	int countSegments(std::string s) {
		int result = 0;
		bool count = false;
		for(char c : s)
		{
			if(c == ' ')
			{
				if(count == true)
				{
					count = false;
					result++;
				}
			}
			else
			{
				count = true;
			}
		}

		if(count ==true) result++;

		return result;
	}

};



//int main()
//{
//	Solution so;
//
//	int result = so.countSegments("Hello, my name is John");
//
//	return 0;
//
//}



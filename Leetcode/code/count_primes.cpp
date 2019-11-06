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

#include <string>


class Solution {
public:
	int countPrimes(int n) {

		for()



	}
};


//使用 埃拉托斯特尼筛法， 第一个质数是2，用2除以后面每个数，删除掉这些能被2整除的数，
//然后找下一个数，3，用3除以后面的每个数，删掉这些被3整除的数,之后下查找下一个数，因为4已经被删除了，找到5，继续同样的操作，就找到所有的质数。


//int main()
//{
//	ListNode* node11 = new ListNode(1);
//	ListNode* node12 = new ListNode(2);
//	node11->next = node12;
//	ListNode* node13 = new ListNode(9);
//	node12->next = node13;
//	ListNode* node14 = new ListNode(3);
//	node13->next = node14;
//	ListNode* node15 = new ListNode(3);
//	node14->next = node15;
//
//	ListNode* node21 = new ListNode(8);
//	ListNode* node22 = new ListNode(9);
//	node21->next = node22;
//	ListNode* node23 = new ListNode(2);
//	node22->next = node23;
//
//	Solution so;
//	ListNode* result = so.addTwoNumbers(node11,node21);
//
//	return 0;
//
//}



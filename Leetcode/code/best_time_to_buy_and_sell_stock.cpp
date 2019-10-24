//--------------------------------------------------------------------
//121. Best Time to Buy and Sell Stock
//Easy
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction(i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//
//Note that you cannot sell a stock before you buy one.
//
//Example 1:
//
//Input: [7, 1, 5, 3, 6, 4]
//	Output : 5
//	Explanation : Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5.
//	Not 7 - 1 = 6, as selling price needs to be larger than buying price.
//	Example 2 :
//
//	Input : [7, 6, 4, 3, 1]
//	Output : 0
//	Explanation : In this case, no transaction is done, i.e.max profit = 0.
//--------------------------------------------------------------------

#include <string>
#include <vector>




class Solution {

public:
	int maxProfit(std::vector<int>& prices) {
		int result = 0;
		int minPrice = -1;
		size_t count = prices.size();
		for(size_t i = 0; i < count; i++)
		{
			if(minPrice == -1 || prices[i] < minPrice)
			{
				minPrice = prices[i];
			}
			else
			{
				int profit = prices[i] - minPrice;
				if(profit > result) result = profit;
			}
		}

		return result;

	}
};



//int main()
//{
//	Solution so;
//	
//
//	std::vector<std::vector<int>> result = so.generate(6);
//
//	return 0;
//
//}


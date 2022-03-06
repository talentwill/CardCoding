// 剑指 Offer 63. 股票的最大利润

// 动态规划，记录i-1前最小值。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        } 

        int maxDiff = 0;
        int minPrice = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - minPrice > maxDiff) {
                maxDiff = prices[i] - minPrice;
            }

            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
        }

        return maxDiff;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = -1;
        int max_profit = 0;
        for (auto price : prices) {
            if (min_price == -1) {
                min_price = price;
            } else if (min_price > price) {
                min_price = price;
            } else {
                max_profit = max(price - min_price, max_profit);
            }
        }
        return max_profit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profits = INT_MIN;

        for (int p : prices){
            profits = max(profits, p-buy);
            buy = min(buy, p);
        }

        return profits;
    }
};

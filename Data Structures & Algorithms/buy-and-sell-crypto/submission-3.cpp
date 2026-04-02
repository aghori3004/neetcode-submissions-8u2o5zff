class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int b = 0; 
       int s = 1;
       int profit = 0;

       while(s < prices.size()){
        if(prices[s] > prices[b]){
            profit = max(profit, prices[s] - prices[b]);
        }
        else b = s;
        s++;
       }

       return max(0, profit);
    }
};

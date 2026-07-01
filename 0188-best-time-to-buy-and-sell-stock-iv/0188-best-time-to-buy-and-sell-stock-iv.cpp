class Solution {
public:
    int helper(vector<int>& prices, int i, int state, int k,
               vector<vector<vector<int>>>& memo) {
        if(k==0) return 0;      
        if (i == prices.size())
            return 0;
        if (memo[i][state][k] != -1)
            return memo[i][state][k];

        int profit = 0;
        if (state == 0) {
            int buy = -prices[i] + helper(prices, i + 1, 1, k,memo);
            int skip = helper(prices, i + 1, 0, k, memo);
            profit = max(buy, skip);
        } else {
            int sell = prices[i] + helper(prices, i + 1, 0, k -1, memo);
            int skip = helper(prices, i + 1, 1, k, memo);
            profit = max(sell, skip);
        }
        return memo[i][state][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<vector<int>>> memo(n , vector<vector<int>>(2, vector<int>(k+1,-1)));
        return helper(prices, 0,0,k,memo);
    }
};
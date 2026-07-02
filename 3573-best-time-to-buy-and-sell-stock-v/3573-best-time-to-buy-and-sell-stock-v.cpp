class Solution {
public:
    long long helper(vector<int>& prices, int i, int state, int k,vector<vector<vector<long long>>>& memo) {
        if(k==0) return 0;      
        if (i == prices.size()){
           if(state == 0){
            return 0;
           }
           else{
            return -1e15;
           }
        }
            
        if (memo[i][state][k] != -1){
            return memo[i][state][k];
        }
        long long profit = 0;
        if (state == 0) {
            long long buy = -prices[i] + helper(prices, i + 1, 1, k,memo);
            long long shortsell = prices[i] + helper(prices, i+1, 2, k, memo);
            long long skip = helper(prices, i + 1, 0, k, memo);
            profit = max({buy, shortsell, skip});
        } else if(state == 1) {
            long long sell = prices[i] + helper(prices, i + 1, 0, k-1 , memo);
            long long skip = helper(prices, i + 1, 1, k, memo);
            profit = max(sell, skip);
        }
        else{
            long long buyback = -prices[i] + helper(prices, i+1, 0, k-1, memo);
            long long skip = helper(prices, i+1, 2, k, memo);
            profit = max(buyback, skip);
        }
        return memo[i][state][k] = profit;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        
        
       
        
        vector<vector<vector<long long>>> memo(n , vector<vector<long long>>(3, vector<long long>(k+1,-1)));
        return helper(prices, 0,0,k,memo);
    }
};
class Solution {
public:
    int helper(vector<int>& prices,int i, int state, int fee, vector<vector<int>>& memo){
        if(i == prices.size()) return 0;
        if(memo[i][state] != -1) return memo[i][state];

        int profit = 0;
        if(state == 0 ){
            int buy = -prices[i] + helper(prices, i + 1, 1,fee, memo);
            int skip = helper(prices, i + 1, 0,fee, memo);
            profit = max(buy, skip);
        }
        else{
            int sell = prices[i] - fee + helper(prices, i + 1, 0, fee, memo);
            int skip = helper(prices, i + 1, 1, fee, memo);
            profit = max(sell,skip);
        }
        return memo[i][state] = profit;
        
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> memo(n , vector<int>(2,-1));
        return helper(prices, 0,0,fee,memo);

        
    }
};
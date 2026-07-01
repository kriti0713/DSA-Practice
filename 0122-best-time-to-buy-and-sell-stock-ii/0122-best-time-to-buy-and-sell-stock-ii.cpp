class Solution {
public:
    int helper(vector<int>& prices,int i, int state, vector<vector<int>>& memo){
        if(i == prices.size()) return 0;
        if(memo[i][state] != -1) return memo[i][state];

        int profit = 0;
        if(state == 0 ){
            int buy = -prices[i] + helper(prices, i + 1, 1, memo);
            int skip = helper(prices, i + 1, 0, memo);
            profit = max(buy, skip);
        }
        else{
            int sell = prices[i] + helper(prices, i + 1, 0, memo);
            int skip = helper(prices, i + 1, 1, memo);
            profit = max(sell,skip);
        }
        return memo[i][state] = profit;
        
    }
    

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n , vector<int>(2,-1));
        return helper(prices, 0,0,memo);



        // int total = 0;

        // for(int i =1; i<prices.size(); i++){
        //     total += max(0, prices[i] - prices[i-1]);
        // }
        // return total;
        
    }
};
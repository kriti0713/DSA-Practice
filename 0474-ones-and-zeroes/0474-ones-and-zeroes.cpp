class Solution {
 int solve(int k, int m, int n, vector<string>& strs, vector<vector<vector<int>>>& memo) {
    if(k == strs.size()) return 0;

    if (memo[k][m][n] != -1) return memo[k][m][n];

       int dontpick = solve(k + 1, m, n, strs, memo);
       int pick = 0;

       int zeros = 0;
       int ones = 0;
       for (char c : strs[k]) {
          if (c == '0') zeros++;
            else ones++;
        }

        if (m >= zeros && n >= ones) {
            pick = 1 + solve(k + 1, m - zeros, n - ones, strs, memo); 
        }

        return memo[k][m][n] = max(dontpick, pick);
 }      
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();

        vector<vector<vector<int>>> memo(len+1 , vector<vector<int>>(m+1, vector<int>(n+1,-1)));
       
         return solve(0, m, n, strs,memo);
        }
    };

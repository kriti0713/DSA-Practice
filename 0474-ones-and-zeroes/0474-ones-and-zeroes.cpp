class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();

        vector<vector<vector<int>>> dp(
            len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        for (int k = 1; k <= len; k++) {
            int zeros = 0;
            int ones = 0;

            for (char c : strs[k - 1]) {
                if (c == '0')
                    zeros++;
                else
                    ones++;
            }

            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    dp[k][i][j] = dp[k - 1][i][j];

                 if (i >= zeros && j >= ones) {
                    dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i - zeros][j - ones] + 1);
                 }     
            }
        }
    }    
         return dp[len][m][n];   
        }
    };

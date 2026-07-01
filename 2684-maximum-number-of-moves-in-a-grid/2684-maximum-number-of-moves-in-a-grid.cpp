class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& memo) {
        int m = grid.size();
        int n = grid[0].size();

        if(memo[r][c] != -1){
            return memo[r][c];
        }

        int maxMoves = 0;
        int dir[] = {-1, 0, 1};

        for(int d : dir){
            int nextR = r + d;
            int nextC = c + 1;

        if (nextR >= 0 && nextR < m && nextC < n && grid[nextR][nextC] > grid[r][c]) {
              maxMoves = max(maxMoves, 1 + dfs(nextR, nextC, grid, memo));
        }
        }
        return memo[r][c] = maxMoves;

    }
   
    int maxMoves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int result = 0;

        vector<vector<int>> memo(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            result = max(result, dfs(i, 0, grid, memo));
        }
        return result;
       
    }
};
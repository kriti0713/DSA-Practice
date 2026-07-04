class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        
       
        if (!dfs(grid, 0, 0, m, n)) return true;
        
      
        grid[m - 1][n - 1] = 1;
        
       
        return !dfs(grid, 0, 0, m, n);
        
    }
    bool dfs(vector<vector<int>>& grid, int r, int c, int m, int n) {
        if (r == m - 1 && c == n - 1) return true;
        grid[r][c] = 0;

        if (r + 1 < m && grid[r + 1][c] == 1 && dfs(grid, r + 1, c, m, n)) return true;
        if (c + 1 < n && grid[r][c + 1] == 1 && dfs(grid, r, c + 1, m, n)) return true;
        
        return false;
    }
};
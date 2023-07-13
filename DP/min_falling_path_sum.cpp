// memorization:
class Solution {
public:
    int findMinPath(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return INT_MAX;
        }
        if (i == n - 1) {
            return grid[i][j];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int left = findMinPath(i + 1, j - 1, grid, dp);
        int down = findMinPath(i + 1, j, grid, dp);
        int right = findMinPath(i + 1, j + 1, grid, dp);

        dp[i][j] = grid[i][j] + min(left, min(down, right));
        return dp[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int minSum = INT_MAX;
        for (int j = 0; j < n; j++) {
            minSum = min(minSum, findMinPath(0, j, grid, dp));
        }

        return minSum;
    }
};

==========================
//tabulation:
class Solution {
public:
     int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // Base case: Initialize the first row of dp
        for (int j = 0; j < n; j++) {
            dp[0][j] = grid[0][j];
        }

        // Compute the minimum falling path sum for each cell
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int left = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
                int right = (j < n - 1) ? dp[i - 1][j + 1] : INT_MAX;
                dp[i][j] = min(left, min(dp[i - 1][j], right)) + grid[i][j];
            }
        }

        // Find the minimum falling path sum in the last row
        int minSum = INT_MAX;
        for (int j = 0; j < n; j++) {
            minSum = min(minSum, dp[n - 1][j]);
        }

        return minSum;
    }
};

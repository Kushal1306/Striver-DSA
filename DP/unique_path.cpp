class Solution {
public:
   int countpaths(int i,int j,int m, int n,vector<vector<int>>&dp)
   {
       if(i==m-1&&j==n-1)
       return 1;
       if(i>=m||j>=n)
       return 0;
       if(dp[i][j]!=-1)
       return dp[i][j];

       return dp[i][j]=countpaths(i+1,j,m,n,dp)+countpaths(i,j+1,m,n,dp);

   }
    int uniquePaths(int m, int n) {
       vector<vector<int>>dp(m,vector<int>(n,-1));

       return countpaths(0,0,m,n,dp); 
    }
};

//// tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Base case: There is one way to reach any cell in the first row or first column
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;

        // Fill the dp table using bottom-up approach
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // The number of unique paths to reach cell (i, j) is the sum of paths from above cell (i-1, j) and left cell (i, j-1)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // The result is stored in the bottom-right cell of the dp table
        return dp[m - 1][n - 1];
    }
};
===================
//space optimization:
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1); // Initialize the dp array with 1's

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // The number of unique paths to reach cell (i, j) is the sum of paths from above cell (i-1, j) and left cell (i, j-1)
                dp[j] += dp[j - 1];
            }
        }

        // The result is stored in the last element of the dp array
        return dp[n - 1];
    }
};

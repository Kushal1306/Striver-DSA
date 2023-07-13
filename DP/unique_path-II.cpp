//just an addition to unique path questions .. just handling a test case.
class Solution {
public:
int find(int i,int j,int n, int m,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid)
{

    if(i==(n-1) && j==(m-1)) return 1;
    if(i>=n||j>=m||obstacleGrid[i][j]==1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
   else return dp[i][j]=find(i+1,j,n,m,dp,obstacleGrid)+ find(i,j+1,n,m,dp,obstacleGrid);
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1)
        return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return find(0,0,n,m,dp,obstacleGrid);
    }
};
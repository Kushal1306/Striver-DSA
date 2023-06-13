//Brute force solution with explonential time complexity
int countpaths(int i,int j,int n, int m)
    {
        if(i==(n-1) && j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        else return countpaths(i+1,j,n,m)+ countpaths(i,j+1,n,m);
    }
    int uniquePaths(int n, int m) {
        return countpaths(0,0,n,m);
    }
/*---------------------------------------------------------------*/
//DP solution with O(n*m) TC
  int countpaths(int i,int j,int n, int m,vector<vector<long long>>&dp)
    {
        if(i==(n-1) && j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        else return dp[i][j]=countpaths(i+1,j,n,m,dp)+ countpaths(i,j+1,n,m,dp);
    }
    int uniquePaths(int n, int m) {
        vector<vector<long long>>dp(n,vector<long long>(m,-1));
        return countpaths(0,0,n,m,dp);
    }


//memorization
class Solution {
public:
   int minipathsum(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp)
   {
       if(i==n-1)
       {
           return triangle[n-1][j];
       }
       if(dp[i][j]!=-1)
       return dp[i][j];

       int left=triangle[i][j]+minipathsum(i+1,j,n,triangle,dp);
       int right=triangle[i][j]+minipathsum(i+1,j+1,n,triangle,dp);

       return dp[i][j]=min(left,right);


   }
    int minimumTotal(vector<vector<int>>& triangle) {
     int n=triangle.size();
     vector<vector<int>>dp(n,vector<int>(n,-1));
     return minipathsum(0,0,n,triangle,dp);
    }
};
==========================================
//tabulation
int minimumPathSum(vector<vector<int> > &triangle, int n){
    vector<vector<int> > dp(n,vector<int>(n,0));
    
    for(int j=0;j<n;j++){
        dp[n-1][j] = triangle[n-1][j];
    }
    
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            
            int down = triangle[i][j]+dp[i+1][j];
            int diagonal = triangle[i][j]+dp[i+1][j+1];
            
            dp[i][j] = min(down, diagonal);
        }
    }
    
    return dp[0][0];
    
}
/*Time Complexity: O(N*N)

Reason: There are two nested loops

Space Complexity: O(N*N)

Reason: We are using an external array of size ‘N*N’. The stack space will be eliminated.*/
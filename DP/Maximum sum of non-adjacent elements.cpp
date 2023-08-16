// Maximum sum of non-adjacent elements
//dp: memorization
#include <bits/stdc++.h> 
int f(int ind,vector<int>&nums,vector<int>&dp)
{
    if(ind==0)return nums[ind];
    if(ind<0)return 0;
    if(dp[ind]!=-1)
    return dp[ind];
    
    int pick=nums[ind]+f(ind-2,nums,dp);
    int notpick=0+f(ind-1,nums,dp);

    return dp[ind]=max(pick,notpick);

}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int>dp(n,-1);
    return f(n-1,nums,dp);
}
.....................................
// space optimization
int solve(int n, vector<int>& arr){
    int prev = arr[0];
    int prev2 =0;
    
    for(int i=1; i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev;
        
        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}
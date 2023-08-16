// problem link:https://www.codingninjas.com/studio/problems/frog-jump_3621012

// solution 1: recursion
#include <bits/stdc++.h> 

int find(int index,vector<int>&heights)
{
    if(index==0)
    return 0;
    int jump1=find(index-1,heights)+abs(heights[index]-heights[index-1]);
    int jump2=INT_MAX;
    if(index>1)jump2=find(index-2,heights)+abs(heights[index]-heights[index-2]);

    return min(jump1,jump2);
}
int frogJump(int n, vector<int> &heights)
{
    return find(n-1,heights);
    
}
///////////////////////////////////
//Memorization solution: using dp .. converting recursion to dp
#include <bits/stdc++.h> 

int find(int index,vector<int>&heights,vector<int>&dp)
{
    if(index==0)
    return 0;
    if(dp[index]!=-1)
    return dp[index];
    int jump1=find(index-1,heights,dp)+abs(heights[index]-heights[index-1]);
    int jump2=INT_MAX;
    if(index>1)jump2=find(index-2,heights,dp)+abs(heights[index]-heights[index-2]);

    return dp[index]=min(jump1,jump2);
}
int frogJump(int n, vector<int> &heights)
{   vector<int>dp(n+1,-1);
    return find(n-1,heights,dp);
    
}

-------------------------------
// tabulation:

int frogJump(int n, vector<int> &heights)
{   vector<int>dp(n,0);
dp[0]=0;
for(int i=1;i<n;i++)
{
    int first_step=dp[i-1]+abs(heights[i]-heights[i-1]);
    int second_step=INT_MAX;
    if(i>1)second_step=dp[i-2]+abs(heights[i]-heights[i-2]);

dp[i]=min(first_step,second_step);
}
return dp[n-1];
   // return find(n-1,heights,dp);
    
}
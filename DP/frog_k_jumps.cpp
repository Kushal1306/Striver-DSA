// recursion: we will get TLE
#include<bits/stdc++.h>

int find(int n,int k,vector<int>&height)
{
     if(n==0)
    return 0;
    int min_steps=INT_MAX;
    for(int j=1;j<=k;j++)
    {
        if(n-j>=0){
       int jump=find(n-j,k,height)+abs(height[n]-height[n-j]);
        min_steps=min(jump,min_steps);
        }
      

    }
    return min_steps;
}
int minimizeCost(int n, int k, vector<int> &height){
    
   return find(n-1,k,height);

}
-------------------------------------------------------
//using memorization
#include<bits/stdc++.h>

vector<int> dp;

int find(int n, int k, vector<int>& height)
{
    if (n == 0)
        return 0;
    
    if (dp[n] != -1)
        return dp[n];
    
    int min_steps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (n - j >= 0)
        {
            int jump = find(n - j, k, height) + abs(height[n] - height[n - j]);
            min_steps = min(jump, min_steps);
        }
    }
    
    dp[n] = min_steps;
    return min_steps;
}

int minimizeCost(int n, int k, vector<int>& height)
{
    dp.resize(n, -1);
    return find(n - 1, k, height);
}

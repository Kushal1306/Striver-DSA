//recursion approach
#include<bits/stdc++.h>
int find(int day,int last,vector<vector<int>>&points){
    if(day==0)
    {
        int maxi=0;
        for(int task=0;task<3;task++)
        {  if(task!=last)
           maxi=max(maxi,points[0][task]);
        }
        return maxi;
    }
    
    int maxi=0;
    for(int task=0;task<3;task++)
    {
        if(task!=last)
        {
            int point=points[day][task]+find(day-1,task,points);
            maxi=max(maxi,point);
        }
    }
    return maxi;


}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
  //  vector<vector<int>>dp(n,vector<int>(4,-1));


    return find(n-1,3,points);

}
==============================================================
//////using dp memorizatom
#include<bits/stdc++.h>
int find(int day,int last,vector<vector<int>>&points,vector<vector<int>>&dp){
    if(day==0)
    {
        int maxi=0;
        for(int task=0;task<3;task++)
        {  if(task!=last)
           maxi=max(maxi,points[0][task]);
        }
        return maxi;
    }
    if(dp[day][last]!=-1)
    return dp[day][last];
    
    int maxi=0;
    for(int task=0;task<3;task++)
    {
        if(task!=last)
        {
            int point=points[day][task]+find(day-1,task,points,dp);
            maxi=max(maxi,point);
        }
    }
    return dp[day][last]=maxi;


}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4,-1));


    return find(n-1,3,points,dp);
}

/*Time Complexity: O(N*4*3)

Reason: There are N*4 states and for every state, we are running a for loop iterating three times.

Space Complexity: O(N) + O(N*4)

Reason: We are using a recursion stack space(O(N)) and a 2D array (again O(N*4)). Therefore total space complexity will be O(N) + O(N) ≈ O(N)*/
===================================================================
//tabulation:
int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < vector < int > > dp(n, vector < int > (4, 0));

  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {
    for (int last = 0; last < 4; last++) {
      dp[day][last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          int activity = points[day][task] + dp[day - 1][task];
          dp[day][last] = max(dp[day][last], activity);
        }
      }
    }

  }

  return dp[n - 1][3];
}
/*Time Complexity: O(N*4*3)

Reason: There are three nested loops

Space Complexity: O(N*4)

Reason: We are using an external array of size ‘N*4’’.
*/
==========================================================================================
// space optimization
int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < int > prev(4, 0);

  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {

    vector < int > temp(4, 0);
    for (int last = 0; last < 4; last++) {
      temp[last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          temp[last] = max(temp[last], points[day][task] + prev[task]);
        }
      }
    }

    prev = temp;

  }

  return prev[3];
}

/*Time Complexity: O(N*4*3)

Reason: There are three nested loops

Space Complexity: O(4)

Reason: We are using an external array of size ‘4’ to store only one row.
*/
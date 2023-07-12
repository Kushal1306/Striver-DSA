//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
   void findsum(int index,int sum,vector<int>&ans,vector<int>&arr,int n)
   {  
       if(index==n)
       {
           ans.push_back(sum);
           return;
       }
       //picking number
       findsum(index+1,sum+arr[index],ans,arr,n);

       ///not picking number
       findsum(index+1,sum,ans,arr,n);
       
       
   }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans;

        findsum(0,0,ans,arr,N);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
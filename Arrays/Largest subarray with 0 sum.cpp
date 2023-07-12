int maxLen(vector<int>&nums, int n)
    {   
        // Your code here
        int maxi=0,sum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum==0)
            {
                maxi=i+1;
                
            }
            else
            {
                if(mp.find(sum)!=mp.end())
                {
                    maxi=max(maxi,i-mp[sum]);
                }
                else
                {
                    mp[sum]=i;
                }
            }
            
        }
        return maxi;
    }
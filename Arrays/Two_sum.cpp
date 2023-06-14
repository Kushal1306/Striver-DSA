//brute force approach
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>kkj;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
            if(nums[i]+nums[j]==target)
            {
               kkj.push_back(i);
                kkj.push_back(j);
            }

        }
        }
        return kkj;
        
    }
/*-------------------------------------*/
//two pointer approach
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>res,store;
    store=nums;
    sort(store.begin(),store.end());
    int left=0;
    int right=nums.size()-1;
    int n1,n2;
    while(left<right)
    {
        if(store[left]+store[right]==target)
        {
            n1=store[left];
            n2=store[right];
        }
        else if(store[left]+store[right]>target)
        right--;
        else
        left++;
    }
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==n1)
        res.push_back(i);
        if(nums[i]==n2)
        res.push_back(i);

    }
    return res;
    }
///////////////////////
//optimal solution using hashing
 vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>res;
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++)
    {
        if(mp.find(target-nums[i])!=mp.end())
        {
            res.emplace_back(i);
            res.emplace_back(mp[target-nums[i]]);
            return res;
        }
        mp[nums[i]]=i;
    }
    return res;
    }
class Solution {
public:
    void findPermutations(int indx,vector<int>&nums,vector<vector<int>>&ans)
    {  
    if(indx==nums.size())
    {
    ans.push_back(nums);
    return;
    }
    for(int i=indx;i<nums.size();i++)
    {
        swap(nums[indx],nums[i]);
        findPermutations(indx+1,nums,ans); 
        swap(nums[indx],nums[i]);

    }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>>ans;
        findPermutations(0,nums,ans);
        return ans;


    }
};
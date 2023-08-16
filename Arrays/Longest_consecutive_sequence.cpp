//brute force
 int longestConsecutive(vector<int>& nums) {
        int ans=0,current=1;
        sort(nums.begin(),nums.end());
        int prev=nums[0];
        for(int i=1;i<nums.size();i++)
        {
          if(nums[i]==prev+1)
          current++;
          else if(nums[i]!=prev+1)
          {
              current=1;
          }
          prev=nums[i];
          ans=max(ans,current);
        }
        return ans;
    }
/*----------------------*/
// optimal approach
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>set;
        for(auto it:nums)
        {
            set.insert(it);
        }
        int LongestStreak=0;
        for(auto it:nums)
        {
            if(!set.count(it-1))
            {
                int CurrentNum=it;
                int currentstreak=1;
                while(set.count(CurrentNum+1))
                {
                    CurrentNum++;
                    currentstreak++;
                }
                LongestStreak=max(LongestStreak,currentstreak);
            }
        }
        return LongestStreak;

    }
};
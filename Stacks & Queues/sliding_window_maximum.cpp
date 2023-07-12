// Approach 1:- brute force TC: O((n-k+1) * k) The outer loop runs 
// (n-k+1) times because we iterate over each possible window of size k in the array.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        
        for(int i=0;i<=nums.size()-k;i++)
        {   int maxi=INT_MIN;
            for(int j=i;j<i+k;j++)
            {
                maxi=max(maxi,nums[j]);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};
/*----------------------------------------*/
// Approach 2
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;        // Resultant vector to store maximum elements

        deque<int> dq;          // Deque to store indices of potential maximum elements

        for(int i = 0; i < nums.size(); i++) {
            if(!dq.empty() && dq.front() == i - k)    // Remove elements outside the window
                dq.pop_front();

            while(!dq.empty() && nums[dq.back()] <= nums[i])   // Remove smaller elements from the back
                dq.pop_back();

            dq.push_back(i);       // Add current element to the deque

            if(i >= k - 1)         // Start adding maximum elements to the result vector from k-1 index
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

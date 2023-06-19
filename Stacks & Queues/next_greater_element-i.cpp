// approach1
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        unordered_map<int, int> nextGreater;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nextGreater[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            if (nextGreater.find(nums1[i]) != nextGreater.end()) {
                ans.push_back(nextGreater[nums1[i]]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
////////////////////////////////////////////////////////////////

//approach 2
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         int n=nums2.size();
        vector<int>ans(n,-1);
        vector<int>ans2;
        stack<int>st;
        map<int,int>kkj;

       for (int i = n-1;i>=0;i--)
        { 
            while(!st.empty()&&st.top()<=nums2[i])
            {
                 st.pop();
            }
            if(st.empty()==false)
            ans[i]=st.top();
          //  else removed this step ans i initialised vector with -1 values
        //    ans[i]=-1;
            kkj.insert({nums2[i],ans[i]});
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++)
        { 
            ans2.push_back(kkj[nums1[i]]);

        }
        return ans2;
    }
};
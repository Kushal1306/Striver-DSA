vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> st;
    vector<int> ans(A.size(), -1);
    for (int i = 0; i < A.size(); i++) {
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }
        if (!st.empty()) {
            ans[i] = st.top();
        }
        st.push(A[i]);
    }
    return ans;
}

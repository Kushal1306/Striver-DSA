//Approach 1 using a pair. TC: O(1), SC: O(2*N)
// inserting a pair and maintaining minimum value
class MinStack {
public:
    stack<pair<int, int>> st;  // Stack to store elements and corresponding minimum values
    
    MinStack() {
        
    }
    
    void push(int val) {
        int mini = st.empty() ? val : min(val, st.top().second);  // Calculate the new minimum value
        st.push({val, mini});  // Push the element and its minimum value to the stack
    }
    
    void pop() {
        st.pop();  // Pop the top element from the stack
    }
    
    int top() {
        return st.top().first;  // Return the element at the top of the stack
    }
    
    int getMin() {
        return st.top().second;  // Return the minimum value stored in the top element of the stack
    }
};
// ?*-----------------------------------------------------------*
//Approach-2
class MinStack {
  stack < long long > st;
  long long mini;
  public:
    /** initialize your data structure here. */
    MinStack() {
      while (st.empty() == false) st.pop();
      mini = INT_MAX;
    }

  void push(int value) {
    long long val = Long.valuevalue;
    if (st.empty()) {
      mini = val;
      st.push(val);
    } else {
      if (val < mini) {
        st.push(2 *val*1LL - mini);
        mini = val;
      } else {
        st.push(val);
      }
    }
  }

  void pop() {
    if (st.empty()) return;
    long long el = st.top();
    st.pop();

    if (el < mini) {
      mini = 2 * mini - el;
    }
  }

  int top() {
    if (st.empty()) return -1;

    long long el = st.top();
    if (el < mini) return mini;
    return el;
  }

  int getMin() {
    return mini;
  }
};
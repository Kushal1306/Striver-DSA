class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word;
       

        for (int i = 0; i < s.length(); i++) 
        {
            if (!isspace(s[i])) 
            {
                word += s[i];
            } 
            else if (!word.empty()) 
            {
                st.push(word);
                word = "";
            }
        }

        if (!word.empty()) {
            st.push(word);
        }

        word="";
        while (!st.empty()) 
        {
            word += st.top();
            st.pop();
            if (!st.empty()) {
                word += " ";
            }
        }

        return word;
    }
};

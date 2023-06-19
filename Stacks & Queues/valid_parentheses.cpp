class Solution {
public:
    bool isValid(string s) {
        stack<char>kkj;
        for(auto i:s)
        {
            if(i=='(' or i=='{' or i=='[') 
            kkj.push(i);
            else
            {
                if( kkj.empty() or ( kkj.top()=='(' and i!=')') or(kkj.top()=='{' and i!='}') or(kkj.top()=='[' and i!=']'))
                return false;
                else
                kkj.pop();
            }

        }
        return kkj.empty();
    }
};
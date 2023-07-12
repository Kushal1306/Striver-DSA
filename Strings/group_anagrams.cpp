class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
       
        map<string,vector<string>>mp;
        int k=0;
        for(auto x:str){
           string s=x;
           sort(begin(s),end(s));
           mp[s].push_back(x);
        }
        
        vector<vector<string>>res;
        for(auto x:mp)
         res.push_back(x.second);

        return res; 
    }
};
/*god algorithm logarithm dog soup peer reep pour pous proud drop */
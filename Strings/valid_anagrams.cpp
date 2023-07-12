//appraoch 1 using sorting TC: O(n*logn)
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t)
            return true;
        else
            return false;
        
    }
};



//approach 2: TC: O(N)
#include <iostream>
#include <string>
#include <array>

bool areAnagrams(const std::string& str1, const std::string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    std::array<int, 26> freqCount1{0};
    std::array<int, 26> freqCount2{0};

    for (char c : str1) {
        freqCount1[c - 'a']++;
    }

    for (char c : str2) {
        freqCount2[c - 'a']++;
    }

    return freqCount1 == freqCount2;
}

int main() {
    std::string str1 = "listen";
    std::string str2 = "silent";

    if (areAnagrams(str1, str2)) {
        std::cout << "Strings are anagrams." << std::endl;
    } else {
        std::cout << "Strings are not anagrams." << std::endl;
    }

    return 0;
}

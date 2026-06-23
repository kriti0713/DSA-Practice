class Solution {
public:
    bool isPalindrome(string s) {
        string s2;

        for(char ch : s)
        if(isalnum(ch)) {
            s2 += tolower(ch);
            }

            string rev = s2;
            reverse(rev.begin(),rev.end());
            
            return s2 == rev;
    }
};

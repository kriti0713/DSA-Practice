class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> m1;
        map<char, int> m2;

        for (char ch : s)
            m1[ch]++;

        for (char ch : t)
            m2[ch]++;

        if (m1 == m2)
            return true;
        else
            return false;

        // if (s.length() != t.length()) {
        //     return false;
        // }

        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // return s == t;
    }
};
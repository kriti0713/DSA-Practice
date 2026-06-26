class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> S(sentence.begin(), sentence.end());

        return S.size() == 26;
    }
};
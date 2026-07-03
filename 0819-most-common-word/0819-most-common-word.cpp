class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        set<string> banset(banned.begin(), banned.end());
        map<string, int> wordcount;

        string result = "";
        int maxcount = 0;
        string currentword = "";

        paragraph += " ";

        for(char c : paragraph) {
            if ( isalpha(c)){
                currentword += tolower(c);
            }
            else if(!currentword.empty()){
                if(banset.find(currentword)== banset.end()){
                    wordcount[currentword]++;
                    if(wordcount[currentword] > maxcount){
                        maxcount = wordcount[currentword];
                        result = currentword;
                    }
                }
                currentword = "";
            }
        }
        return result;
    }
};
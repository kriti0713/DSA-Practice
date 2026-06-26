class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();

        vector<set<char>> ch(n);
        for(int i = 0; i<n; i++){
            for(char c : words[i]){
                ch[i].insert(c);
            }
        }

        int maxValue = 0;

        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                bool matched = false;
                

                for(char c : ch[i]){
                    if(ch[j].count(c)) {
                        matched = true;
                        break;
                    }
                }

                if(!matched){
                    int prod = words[i].length() * words[j].length();
                    maxValue = max(maxValue, prod);
                }
            }
        }

        return maxValue;
        
    }
};
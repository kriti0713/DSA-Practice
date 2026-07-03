class Solution {
public:
    
    int numJewelsInStones(string jewels, string stones) {

     bool isJewel[128] = {false};
     
       for (char j : jewels) {
            isJewel[j] = true;
        }

        int count = 0;
        for (char s : stones) {
            if (isJewel[s]) {
                count++;
            }
        }
        
        return count;
        
    }
};
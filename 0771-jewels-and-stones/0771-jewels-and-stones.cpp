class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        if (stones.empty()) {
            return 0;
        }

        int isJewel = jewels.contains(stones[0]) ? 1 : 0;

        return isJewel + numJewelsInStones(jewels, stones.substr(1));
        
    }
};
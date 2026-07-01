class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int max = 0;

        for(int p : prices){
            if(p< min){
                min = p;
            }
            else if(p - min > max){
                max = p -min;
            }
        }
        return max;
        
    }
};
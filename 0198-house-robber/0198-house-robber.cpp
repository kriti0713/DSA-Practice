class Solution {
public:
    int rob(vector<int>& nums) {
         int house1 = 0;
         int house2 = 0;

         for(int n : nums){
            int current = max(house2, house1 + n);
            house1 = house2;
            house2 = current;
         }

       return house2; 
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n ==2 ) return max(nums[0], nums[1]);

        int house1 = 0;
        int house2 = 0;
        for(int i = 0; i<n-1; i++){
            int current = max(house1 + nums[i], house2);
            house1 = house2;
            house2 = current;
        }
        int max1 = house2;
         house1 = 0;
         house2 = 0;
         for(int i = 1; i <n; i++){
            int current = max(house1+ nums[i], house2);
            house1 = house2;
            house2 = current;
         }
         int max2 = house2;

         return max(max1,max2);
        
    }
};
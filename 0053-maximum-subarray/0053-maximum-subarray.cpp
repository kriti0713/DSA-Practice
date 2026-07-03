class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = nums[0];
        int currentmax = nums[0];

        for(int i = 1; i<nums.size(); i++){
            currentmax = max(nums[i], currentmax + nums[i]);
            maximum = max(maximum, currentmax);
        }
        return maximum;
    }
};
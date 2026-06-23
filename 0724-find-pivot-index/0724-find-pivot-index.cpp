class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        int prefixSum = 0;

        for (int i : nums) {
            totalSum += i;
        }

            for (int i = 0; i < nums.size(); i++) {
            if (prefixSum == totalSum - prefixSum - nums[i]) {
                return i; 
            }
            prefixSum += nums[i];
        }  
        return -1;          
    }
};
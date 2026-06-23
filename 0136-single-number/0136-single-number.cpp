class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int n : nums)
        ans ^= n;

        return ans;


    }
};
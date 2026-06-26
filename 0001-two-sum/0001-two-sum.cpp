class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hashmap;
        for(int i = 0; i<nums.size(); i++){
            int y = target - nums[i];
            if(hashmap.count(y)){
                return {hashmap[y], i};
            }
            hashmap[nums[i]] = i;
        }
        return {};
    }
};
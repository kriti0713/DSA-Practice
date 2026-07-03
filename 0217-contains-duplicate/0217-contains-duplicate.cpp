class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> seen;
        return checkDuplicate(nums, 0, seen);
      
    }
    bool checkDuplicate(vector<int>& nums, int index, unordered_set<int>& seen) {
     if (index == nums.size()) {
            return false;
        }

        if (seen.count(nums[index])) {
            return true;
        }

        seen.insert(nums[index]);
        return checkDuplicate(nums, index + 1, seen);
    }
};
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

         vector<vector<int>> result;
        vector<int> current;
        find(0, target, candidates, current, result);
        return result;

    }

    void find(int i, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {

        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
           
            if (candidates[j] <= target) {
                current.push_back(candidates[j]);
                find(j, target - candidates[j], candidates, current, result);
                current.pop_back();
            }
        }
    }

       
        
    
};
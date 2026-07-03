class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int result = high;

        while(low <= high){
            int mid = low +(high-low)/2;

            if(canRob(nums,k, mid)){
                result = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return result; 
        
    }

    bool canRob(vector<int>& nums, int k, int max){
        int houseRob = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] <= max){
                houseRob++;
                i++;
            }
            if(houseRob >= k) return true;
        }
        return false;
    }
};

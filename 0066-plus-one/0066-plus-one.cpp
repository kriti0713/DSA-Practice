class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        helper(digits, n-1);
        return digits;


        
    }
    void helper(vector<int>& digits, int i){
        if(i<0){
            digits.insert(digits.begin(), 1);
            return;
        }

        if(digits[i] < 9){
            digits[i]++;
        }
        else{
            digits[i] = 0;
            helper(digits, i-1);
        }
    }
};
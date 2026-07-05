class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() -1;
        int j = b.length() -1;
        int k = 0;

        while(i>= 0 || j>=0 || k){
            int sum = k;

            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';

            result += (sum % 2) + '0';
            k = sum/2;
        }

        reverse(result.begin(), result.end());
        return result;
        
    }
};
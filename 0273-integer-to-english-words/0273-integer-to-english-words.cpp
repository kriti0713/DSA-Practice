class Solution {
    const vector<string> BELOW_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const vector<string> TENS = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        if (num < 20) return BELOW_20[num];
        if (num < 100) return TENS[num / 10] + (num % 10 != 0 ? " " + numberToWords(num % 10) : "");
        if (num < 1000) return numberToWords(num / 100) + " Hundred" + (num % 100 != 0 ? " " + numberToWords(num % 100) : "");
        if (num < 1000000) return numberToWords(num / 1000) + " Thousand" + (num % 1000 != 0 ? " " + numberToWords(num % 1000) : "");
        if (num < 1000000000) return numberToWords(num / 1000000) + " Million" + (num % 1000000 != 0 ? " " + numberToWords(num % 1000000) : "");
        
        return numberToWords(num / 1000000000) + " Billion" + (num % 1000000000 != 0 ? " " + numberToWords(num % 1000000000) : "");
        
    }
};
class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;

        for(char ch : num){

            while(!st.empty() && st.back() >ch && k>0){
                st.pop_back(); 
                k--;
            }
            st.push_back(ch);
        }  

            while(k--) 
            st.pop_back();

            while(!st.empty() && st[0] == '0') 
             st.erase(st.begin());
             if(st.empty()) return "0";

            
            
        
        return st;
    }
};
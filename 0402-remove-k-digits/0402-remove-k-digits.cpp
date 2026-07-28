class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n = num.size();
        string res="";

        if(k>=n){return res='0';}

        for(int i=0 ; i<n ; i++){
            while(!st.empty() && num[i]-'0'<st.top()-'0' && k>0){
                st.pop();
                k--;
            }
            // if(st.empty()){
            //     st.push(num[i]);
            // }
            // while(!st.empty() || k<=0){
            //     st.push(num[i]);
            // }
            
            st.push(num[i]);
        }

        while(!st.empty()&& k>0){
            st.pop();
            k--;
        }

        
        if(st.empty()){
            res="";
        }else{
            while(!st.empty()){
                res.push_back(st.top());
                st.pop();
            }

            reverse(res.begin(), res.end());

            
        }

        int i = 0;
        while (i < res.size() && res[i] == '0') {
            i++;
        }

        res = res.substr(i);

        if (res.empty()) {
            return "0";
        }

        return res;


       

    }
};
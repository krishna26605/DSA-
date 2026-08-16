class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();

        unordered_set<char>st;
        int maxcnt=INT_MIN;
        int left=0;

        for(int i=0 ; i<n ; i++){
           
            while(st.find(s[i])!=st.end()){
                st.erase(s[left]);
                left++;
            }

            st.insert(s[i]);

            maxcnt=max(maxcnt,i-left+1);
        }
        if(maxcnt==INT_MIN){
            return 0;
        }else{
            return maxcnt;
        } 
    }
};
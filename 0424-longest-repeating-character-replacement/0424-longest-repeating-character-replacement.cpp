class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int>freq(26);
        int right=0;
        int left=0;
        int maxFreqCount=0;
        int maxlen=0;

        while(right<s.size()){
            freq[s[right]-'A']++;
            maxFreqCount= max(maxFreqCount , freq[s[right]-'A']);

            while(right-left+1-maxFreqCount >k){
                freq[s[left]-'A']--;
                left++;
            }

            maxlen= max(maxlen, right-left+1);

            right++;
        }

        return maxlen;
    }
};
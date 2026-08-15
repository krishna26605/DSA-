class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int n = nums.size();
        unordered_map<int , int>freq;
        long sum=0;
        long maxsum=INT_MIN;


        while(right<n){
            sum = sum + nums[right];
            freq[nums[right]]++;

            if(k==right-left+1){
                if(freq.size()==k){
                    maxsum= max(maxsum, sum);
                }
                sum=sum-nums[left];
                freq[nums[left]]--;
                if(freq[nums[left]]==0){
                    freq.erase(nums[left]);
                }
                left++;
            }
            right++;
        }

        if(maxsum==INT_MIN){
            return 0;
        }else{
            return maxsum;
        }
    }
};
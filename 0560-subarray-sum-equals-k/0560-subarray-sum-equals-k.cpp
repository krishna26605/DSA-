class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<long long , int>mpp;
        int sum=0;
        int count =0;

        mpp[0]=1;

        for(int i=0 ; i<n ; i++){
            sum = sum + nums[i];

            long long rem = sum-k;

            if(mpp.find(rem) != mpp.end()){
                count = count + mpp[rem];
            }

            mpp[sum]++;
        }

        return count;
    }
};
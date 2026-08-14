class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int n = nums.size();
        double  maxavg=INT_MIN;

        int high=0; int low=0 ; int sum=0;
        for(int high=0 ; high<n ; high++){
            sum = sum + nums[high];
            if(k==high-low+1){
                double avg= (double)sum/k;
                maxavg= max(maxavg,avg);
                sum=sum-nums[low];
                low++;
                
            }
        }

        return maxavg;
    }
};
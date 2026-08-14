class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int high=0 ; int low=0 ; int n = arr.size(); int sum=0; int avg=0;
        int cnt=0;

        for(int high=0 ; high<n ; high++){
            sum= sum+arr[high];
            if(k==high-low+1){
                avg=sum/k;

                if(avg>=threshold){
                    cnt++;
                }

                sum= sum-arr[low];
                low++;
            }
        }

        return cnt;
    }
};
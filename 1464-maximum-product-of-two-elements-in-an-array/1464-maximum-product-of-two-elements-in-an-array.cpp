class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max=INT_MIN;
        int secondmax=INT_MIN;
        int n =nums.size();

        for(int i=0 ; i<n ; i++){
            if(nums[i]>=max){
                secondmax=max;
                max=nums[i];
                
            }else{
                if(nums[i]<max && nums[i]>secondmax){
                    secondmax=nums[i];
                }
            }
        }

        return (max-1)*(secondmax-1);

    }
};
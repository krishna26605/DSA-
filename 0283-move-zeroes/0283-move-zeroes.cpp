class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        

        int low =0;
        int high=0;
        int n = nums.size();

        while(high<n){
            if(nums[low]==0){

                if(nums[high]!=0){
                    swap(nums[low], nums[high]);
                    low++;
                    high++;
                }
                else if(nums[high]==0){
                    high++;
                }
            }
            else if(nums[low]!=0){
                low++;
                high++;
            }
        }
    }
};
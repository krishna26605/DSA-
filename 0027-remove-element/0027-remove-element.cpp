class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      
       
        int i=0;
        int n = nums.size();

        for(i=0 ; i<n ; i++){
            if (nums[i]==val){
                break;
            }
        }

        int j=i+1;

        while(j<n){

            if(nums[i]==val){
                if(nums[j]!=val){
                    swap(nums[i], nums[j]);
                    i++;
                    j++;
                }

                else if(nums[j]==val){
                    j++;
                }
            }
        }

        return i;
    }
};
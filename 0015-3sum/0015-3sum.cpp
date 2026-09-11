class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        vector<vector<int>>arr;

        for(int i=0 ; i<nums.size() ; i++){
            int j =i+1;
            int k=nums.size()-1;

            if( i>0 && nums[i]==nums[i-1]) continue;
            else{
                while(j<k){
                    if(nums[i]+nums[j]+nums[k]<0){
                        j++;
                    }
                    else if(nums[i]+nums[j]+nums[k]>0){
                        k--;
                    }
                    else{
                        
                        arr.push_back({nums[i], nums[j] , nums[k]});
                        j++;
                        k--;

                        while(j<k && nums[j]==nums[j-1]){
                            j++;
                        }
                        while(j<k && nums[k]==nums[k+1]){
                            k--;
                        }
                    }
                }
            }

            
        }


        return arr;
        
    }
};
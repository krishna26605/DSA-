class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int n=height.size();
        int r=n-1;
        int lmax=0;
        int rmax=0;
        int sum=0;
        int tmin=INT_MAX;

        while(l<=r){
           
            lmax=max(lmax,height[l]);
            rmax=max(rmax,height[r]);
            tmin =min(lmax,rmax);

            if(height[l]<=height[r]){
                sum+=(tmin-height[l]);
                l++;
            }
            else{
                sum+=(tmin-height[r]);
                r--;
            }

        }

        return sum;


    }
};
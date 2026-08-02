class Solution {
public:
    int maxArea(vector<int>& height) {
        

        int i=0;
        int area;
        int maxa=INT_MIN;

        int n = height.size();
        int j=n-1;

        while(i<j){
            if(height[i]>height[j]){
                area= height[j]*(j-i);
                maxa= max(maxa , area);
                j--;

            }

        else if(height[i]<height[j]){
                area= height[i]*(j-i);
                maxa= max(maxa , area);
                i++;
                
            }

        else if(height[i]==height[j]){
                area= height[i]*(j-i);
                maxa= max(maxa , area);
                i++;
                j--;
            }
        }


        return maxa;

    }
};
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum=0;
        
        for(int i=0 ; i<k ; i++){
            sum=sum+cardPoints[i];
        }
        int maxsum=sum;
        int rindex=n-1;

        for(int i=k-1; i>=0 ;i--){
            sum=sum-cardPoints[i];
            sum=sum+cardPoints[rindex];
            rindex=rindex-1;
            maxsum=max(maxsum, sum);
        }

        return maxsum;
    }
};
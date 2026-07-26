class Solution {
public:

vector<int>FindPSE(vector<int>arr){
    int n =arr.size();
    stack<int>st;
    vector<int>ans(n);

    for(int i=0 ; i<n ; i++){
        while(!st.empty() && arr[i]<arr[st.top()]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}

vector<int>FindNSE(vector<int>arr){
    int n = arr.size();
    stack<int>st;
    vector<int>ans(n);

    for(int i=n-1 ; i>=0 ; i--){
        while(!st.empty() && arr[i]<=arr[st.top()]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=n;
        }
        else{
            ans[i]=st.top();
        }
        st.push(i);
    }

    return ans;
}









    int largestRectangleArea(vector<int>& heights) {

        int n= heights.size();
        vector<int>pse=FindPSE(heights);
        vector<int>nse=FindNSE(heights);
        int maxi=INT_MIN;

        for(int i=0 ; i<n ; i++){

            int ppse= pse[i];
            int nnse=nse[i];
            int diff= (nnse-ppse)-1;
            int area= heights[i]*diff;

            maxi=max(maxi,area);

        }

        return maxi;
    }
};
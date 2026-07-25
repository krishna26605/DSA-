class Solution {




public:

vector<int> FindNSE(vector<int> arr){
    int n = arr.size();
    stack<int>st;
    vector<int>ans(n);

    for(int i=n-1; i>=0 ; i-- ){
        while(!st.empty() && arr[st.top()]>=arr[i]){
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

vector<int>FindPSE(vector<int>arr){
    int n=arr.size();
    stack<int>st;
    vector<int>ans(n);

    for(int i=0 ; i<n ; i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
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

vector<int>NGE(vector<int>arr){
    int n = arr.size();
    stack<int>st;
    vector<int>ans(n);

    for(int i=n-1; i>=0;i--){

        while(!st.empty() && arr[st.top()]<=arr[i]){
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

vector<int>PGE(vector<int>arr){
    int n=arr.size();
    stack<int>st;
    vector<int>ans(n);

    for(int i=0 ; i<n ; i++){
        while(!st.empty() && arr[st.top()]<arr[i]){
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

long long subarrayMax(vector<int> & arr){
    vector<int>pge=PGE(arr);
    vector<int>nge=NGE(arr);

    int n=arr.size();
    long long  sum=0;

    for(int i=0 ; i<n ; i++){
        int left = i-pge[i];
        int right=nge[i]-i;

        long long freq= left*right*1LL;
        long long contri = freq*arr[i]*1LL;

        sum = sum + contri;
    }

    return sum;
}

long long subarrayMin(vector<int> & arr){

    vector<int>pse= FindPSE(arr);
    vector<int>nse= FindNSE(arr);

    int n = arr.size();
    long long  sum=0;

    for(int i=0 ;i<n ; i++){

        int left = i-pse[i];
        int right= nse[i]-i;

        long long freq = left*right*1LL;

        long long contri = arr[i]*freq*1LL;

        sum = sum + contri;
    } 
    
    return sum;
}



    long long subArrayRanges(vector<int>& nums) {
        
        return ( subarrayMax(nums) - subarrayMin(nums) );

    }
};
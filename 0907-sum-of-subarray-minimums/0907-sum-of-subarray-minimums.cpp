class Solution {
vector<int>findNSE(vector<int> &arr){
    int n= arr.size();

    stack<int>st;
    vector<int>ans(n);

    for(int i=n-1; i>=0 ; i--){
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

vector<int>FindPSE(vector<int> & arr){
    int arrsize= arr.size();
    stack<int>stk;
    vector<int>answer(arrsize);

    for(int i=0 ; i<arrsize ; i++){
        while(!stk.empty() && arr[stk.top()]>arr[i]){
            stk.pop();
        }
        if(stk.empty()){
            answer[i]=-1;
        }
        else{
            answer[i]=stk.top();
        }
        stk.push(i);
    }

    return answer;
}

public:
    int sumSubarrayMins(vector<int>& arr) {

        vector<int>nse=findNSE(arr);
        vector<int>pse=FindPSE(arr);

        int s =arr.size();
        long sum=0;
        int mod = 1e9+7;

        for(int i=0 ;i<s ; i++){
            int left = i-pse[i];
            int right= nse[i]-i;

            long long freq= left*right*1LL;

            int contri= (arr[i]*freq*1LL)%mod;

            sum= (sum+contri)%mod;
        }
        
        return sum;
    }
};
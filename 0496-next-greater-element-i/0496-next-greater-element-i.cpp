class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n =nums1.size();
        int i=0;
        int k=nums2.size();

        while(i<n){
            for (int j=k-1 ; j>=0 ; j--){
                if(nums1[i]==nums2[j]){
                    if(st.empty()){
                        nums1[i]=-1;
                        st.push(nums2[j]);
                    }
                     
                    else{
                        while(!st.empty() && st.top()<=nums1[i]){
                            st.pop();
                        }
                        if(st.empty()){
                            nums1[i]=-1;
                            st.push(nums2[j]);
                            
                        }
                        else{
                            nums1[i]=st.top();
                            st.push(nums2[j]);
                        }
                       

                    }
                }
                else{
                    st.push(nums2[j]);
                }
            }
            i++;
            while(!st.empty()){
                st.pop();
            }
        }

        return nums1;
    }
};
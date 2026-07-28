class StockSpanner {
    stack<pair<int,int>>st;
    int i;


public:

    StockSpanner(){
        i=-1;
    }
    
    
    int next(int price) {

        i++;
        
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int ans;
        if(st.empty()){
            ans=i+1;
        }else{
            ans= i- st.top().second;
        }

        st.push({price,i});

        return ans;
        
    }

   
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
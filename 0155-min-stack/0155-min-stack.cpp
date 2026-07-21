class MinStack {

    stack<long long >st;
    long long min=LLONG_MAX;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            min=value;
        }

        else{
            if(value>=min){
                st.push(value);
            }
            else{
                st.push((2LL*value)-min);
                min=value;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();

        if(x<min){
            min=2*min-x;
        }

        if(st.empty()){
            min=LLONG_MAX;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long x=st.top();
        if(x>=min) return x;
        else {
            return min;
        }
    }
    
    int getMin() {
        if(st.empty())return -1;
        else{
            return min;
        }
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
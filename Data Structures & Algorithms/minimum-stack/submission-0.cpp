class MinStack {
public:
stack<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int value) {
        int minimum=INT_MAX;
        if(st.empty()){
            minimum=value;
        }else{
            minimum=min(value,st.top().second);
        }
        st.push({value,minimum});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

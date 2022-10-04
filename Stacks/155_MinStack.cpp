class MinStack {
private:
    int currentMin = INT_MAX;
    stack<pair<int,int>> vals;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        currentMin = min(currentMin, val);
        vals.push({val, currentMin});
    }
    
    void pop() {
        vals.pop();
        if (!vals.empty())
            currentMin = vals.top().second;
        else 
            currentMin = INT_MAX;
    }
    
    int top() {
        return vals.top().first;
    }
    
    int getMin() {
        return vals.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
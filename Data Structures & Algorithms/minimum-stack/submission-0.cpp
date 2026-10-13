class MinStack {
private: 
    std::stack<int> mainStack;
    std::stack<int> recordMin;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        mainStack.push(value);
        if (recordMin.empty() || value <= recordMin.top()){
            recordMin.push(value);
        }
    }
    
    void pop() {
        if (mainStack.top() == recordMin.top()){
            recordMin.pop();
        }
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return recordMin.top();
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
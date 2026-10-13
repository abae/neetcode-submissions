class MyQueue {
private:
    std::stack<int> input_;
    std::stack<int> output_;
public:
    MyQueue() {}
    
    void push(int x) {
        if (input_.size() == 0){
            while (!output_.empty()){
                input_.push(output_.top());
                output_.pop();
            }
        }
        input_.push(x);
    }
    
    int pop() {
        if (output_.size() == 0){
            while (!input_.empty()){
                output_.push(input_.top());
                input_.pop();
            }
        }
        int out = output_.top();
        output_.pop();
        return out;
    }
    
    int peek() {
        if (output_.size() == 0){
            while (!input_.empty()){
                output_.push(input_.top());
                input_.pop();
            }
        }
        return output_.top();
    }
    
    bool empty() {
        return (input_.empty() && output_.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
class MyQueue {
private:
    stack<int> in_;
    stack<int> out_;
        
public:
    MyQueue() = default;
    
    void push(int x) {
        in_.push(x);
    }
    
    int pop() {
        move_to_out();
        const int ans = out_.top();
        out_.pop();
        return ans;
    }
    
    int peek() {
        move_to_out();
        return out_.top();        
    }
    
    bool empty() {
        return ::empty(in_) && ::empty(out_);
    }
    
private:
    void move_to_out() {
        if (!::empty(out_)) return;
        
        while (!::empty(in_)) {
            out_.push(in_.top());
            in_.pop();
        }
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
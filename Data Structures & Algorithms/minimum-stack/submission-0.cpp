class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;
public:
    MinStack() {
        mainStack = stack<int>();
        minStack = stack<int>();
    }
    
    void push(int val) {
        mainStack.push(val);
        if(minStack.empty()) {
            minStack.push(val);
        } else if(val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        int top = mainStack.top();
        mainStack.pop();
        if(top == minStack.top()) {
            minStack.pop();
        }
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
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
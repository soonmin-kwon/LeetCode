/*************
 * Min Stack *
 *************/

class MinStack {
public:
    stack<int> s;
    stack<int> sMin;
    
    /** initialize your data structure here. */
    MinStack() {        
        
    }
    
    void push(int val) {
        s.push(val);
        
        //최소값을 top으로 갖고 있는 stack을 만들기 위해 따로 push
        //비어있으면 그냥 push
        if(sMin.empty() || val <= sMin.top()) {
            sMin.push(val);
        }
    }
    
    void pop() {
        //비어 있으면 return
        if(s.empty()){
            return;
        }
        
        //최소 값을 pop 하려고 하면 최소값을 갖고 있는 stack에서도 pop
        if(s.top() == sMin.top() && !sMin.empty()){
            sMin.pop();
        }        
        s.pop();
    }
    
    int top() {        
        return s.top();                        
    }
    
    int getMin() {
        return sMin.top();
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
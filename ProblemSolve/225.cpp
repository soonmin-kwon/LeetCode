/********************************
 * Implement Stack using Queues *
 ********************************/

class MyStack {
private:
    queue<int> stack;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    //push할때 미리 pop하기 좋은 구조로 변경한다.
    //O(n)
    void push(int x) {
        stack.push(x);
        
        //맨 마지막에 들어온 원소가 제일 앞으로 와야하므로 하나빼고 전부 뒤로 보낸다
        for(int i=1; i<stack.size(); i++){
            stack.push(stack.front());
            stack.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        //비어있는 경우
        if(stack.empty()){
            return -1;
        }
        
        //이미 stack의 구조처럼 queue에 들어온 순서 반대로 queue를 구현했기 때문에
        //front값이 stack의 top값이다
        int top = stack.front();
        stack.pop();
        
        return top;
    }
    
    /** Get the top element. */
    int top() {
        //위의 pop과 동일
        return stack.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return stack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
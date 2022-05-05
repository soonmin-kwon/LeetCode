/********************************
 * Implement Stack using Queues *
 ********************************/

public class MyStack {
    private Queue<int> stack = new Queue<int>();
    
    public MyStack() {
        
    }
    
    public void Push(int x) {
        stack.Enqueue(x);
        
        for(int i=1; i<stack.Count; ++i){
            stack.Enqueue(stack.Dequeue());
        }
    }
    
    public int Pop() {
        if(stack.Count == 0){
            return -1;
        }
        
        return stack.Dequeue();
    }
    
    public int Top() {
        return stack.Peek();
    }
    
    public bool Empty() {
        return stack.Count == 0;
    }
}
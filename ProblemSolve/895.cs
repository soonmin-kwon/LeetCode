/***************************
 * Maximum Frequency Stack *
 ***************************/

public class FreqStack {
    Dictionary<int, int> frequency = new Dictionary<int, int>();
    Dictionary<int, Stack<int>> freqStack = new Dictionary<int, Stack<int>>();
    int maxFrequency = 0;
    
    public FreqStack() {
    }
    
    public void Push(int val) {
        int freq = frequency.GetValueOrDefault(val) + 1;
        frequency[val] = freq;
        
        maxFrequency = Math.Max(freq, maxFrequency);
        
        if(freqStack.TryGetValue(freq, out Stack<int> st)){
            st.Push(val);
        }
        else{
            freqStack[freq] = new Stack<int>();
            freqStack[freq].Push(val);
        }
    }
    
    public int Pop() {
        int top = freqStack[maxFrequency].Pop();
        frequency[top] -= 1;
        
        if(freqStack[maxFrequency].Count == 0){
            maxFrequency--;
        }
        
        return top;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.Push(val);
 * int param_2 = obj.Pop();
 
 
 
 */
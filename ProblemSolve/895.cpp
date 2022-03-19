/***************************
 * Maximum Frequency Stack *
 ***************************/

class FreqStack {
public:
    unordered_map<int, int> freqCount;
    unordered_map<int, stack<int>> freqStack;
    int maxFreq = 0;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        freqCount[val]++;
        int frequency = freqCount[val];
        
        maxFreq = max(maxFreq, frequency);
        freqStack[frequency].push(val);
    }
    
    int pop() {
        int top = freqStack[maxFreq].top();
        freqStack[maxFreq].pop();
        freqCount[top]--;
        
        if(freqStack[maxFreq].empty()){
            maxFreq--;
        }

        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */ 
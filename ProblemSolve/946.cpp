/****************************
 * Validate Stack Sequences *
 ****************************/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int len = pushed.size();
        stack<int> st;
        
        int popIdx = 0;
        
        for(int p : pushed){
            st.push(p);
            
            while(!st.empty() && st.top() == popped[popIdx]){
                st.pop();
                popIdx++;
            }
        }
                
        return popIdx == len;
    }
};
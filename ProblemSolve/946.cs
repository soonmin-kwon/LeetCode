/****************************
 * Validate Stack Sequences *
 ****************************/

public class Solution {
    public bool ValidateStackSequences(int[] pushed, int[] popped) {
        int pushedSize = pushed.Length;
        
        Stack<int> st = new Stack<int>();
        
        int popIdx = 0;
        
        foreach(int p in pushed){
            st.Push(p);
            
            while(st.Count != 0 && st.Peek() == popped[popIdx]){
                st.Pop();
                popIdx++;
            }
        }
        
        return popIdx == pushedSize;
    }
}
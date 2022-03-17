/************************
 * Score of Parentheses *
 ************************/

public class Solution {
    public int ScoreOfParentheses(string s) {
        Stack<int> st = new Stack<int>();
        st.Push(0);
        
        foreach(char ch in s){
            if(ch == '('){
                st.Push(0);
            }
            else{
                int currVal = st.Pop();
                int preVal = st.Pop();
                
                st.Push(preVal + Math.Max(currVal * 2, 1));
            }
        }
        
        return st.Pop();
    }
}
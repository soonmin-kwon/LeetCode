/************************
 * Score of Parentheses *
 ************************/

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        
        for(char ch : s){
            if(ch == '('){
                st.push(0);
            }
            else{
                int currValue = st.top();
                st.pop();
                
                int preValue = st.top();
                st.pop();
                
                st.push(preValue + max(2 * currValue, 1));
            }
                
        }
        
        return st.top();
    }
};
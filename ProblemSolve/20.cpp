/*********************
 * Valid Parentheses *
 *********************/

class Solution {
public:
    bool isValid(string s) {                
        stack<char> st;
        int len = s.size();
        
        
        for(int i=0; i<len; i++){
            //왼쪽으로 닫힌 괄호면 스택에 push
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else{
                //오른쪽으로 닫힌 괄호
                //스택이 비어있으면 false;
                if(st.empty()){
                    return false;
                }
                
                //스택의 top에 있는 괄호가 들어오는 괄호와 짝이 맞으면 pop
                if( (st.top() == '(' && s[i] == ')' ) || (st.top() == '{' && s[i] == '}' ) || (st.top() == '[' && s[i] == ']' )){
                    st.pop();
                }
                //다르면 false;
                else{
                    return false;
                }
            }
        }
        //비어있지 않으면, 모두 짝이 맞지 않으면 false
        if(!st.empty()){
            return false;
        }
        
        return true;
    }
};
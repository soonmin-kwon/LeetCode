/********************************************
 * Minimum Remove to Make Valid Parentheses *
 ********************************************/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int len = s.size();
        
        //지워야 하는 괄호를 'D'로 바꿔서 마지막에 지워준다
        for(int i=0; i<len; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                }
                else{
                    s[i] = 'D';
                }
            }
        }
        
        while(!st.empty()){
            s[st.top()] = 'D';
            st.pop();
        }
        
        //'D'로 바뀐 char을 제거
        s.erase(remove(s.begin(), s.end(), 'D'), s.end());
        
        return s;
    }
};
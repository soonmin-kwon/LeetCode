/***********************
 * Basic Calculator II *
 ***********************/

class Solution {
public:
    int calculate(string s) {        
        stack<int> st;
        int len = s.size();
        int ans = 0;
        int curNum = 0;
        char operation = '+';
        char curChar;

        if(len == 0){
            return 0;
        }
                        
        for (int i=0; i<len; i++) {
            curChar = s[i];
            
            if (isdigit(curChar)) {
                curNum = (curNum * 10) + (curChar - '0');
            }
            
            if (!isdigit(curChar) && !iswspace(curChar) || i == len-1) {
                if(operation == '-'){
                    st.push(-curNum);
                }
                else if(operation == '+'){
                    st.push(curNum);
                }
                //먼저 계산되어야 하는 건 먼저 계산해서 stack에 넣어 놓는다.
                else if(operation == '*'){
                    int top = st.top();
                    st.pop();
                    st.push(top * curNum);
                }
                else if (operation == '/'){
                    int top = st.top();
                    st.pop();
                    st.push(top / curNum);
                }
                
                operation = curChar;
                curNum = 0;
            }
        }
                        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};
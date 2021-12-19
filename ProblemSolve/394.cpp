/*****************
 * Decode String *
 *****************/

class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int len = s.size();
        
        for(int i = 0; i < len; i++){
            //한 블록이 닫히기 전까지 전부 push
            if(s[i] != ']') {
                st.push(s[i]);
            }
            else{
                string block = "";
                
                //숫자 직전까지 문자열 생성
                while(st.top() != '['){
                    block = st.top() + block;
                    st.pop();
                }
                
                st.pop();   //'[' 제거
                string number = "";
                
                // '[' 앞에 붙어있는 숫자 계산
                while(!st.empty() && isdigit(st.top())){
                    number = st.top() + number;
                    st.pop();
                }
                
                int times = stoi(number);
                
                //다시 스택에 넣어서 이전에 숫자가 있는 경우에도 적용될 수 있도록 함.
                while(times){
                    times--;
                    for(int j = 0; j < block.size(); j++){
                        st.push(block[j]);
                    }                        
                }
            }
        }
        
        string ans = "";
        
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};
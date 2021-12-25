/***********************
 * Basic Calculator II *
 ***********************/

public class Solution {
    public int Calculate(string s) {
        Stack<int> st = new Stack<int>();
        int curNum = 0;
        int len = s.Length;
        int ans = 0;
        char operation = '+';
        char curChar;
        
        for(int i=0; i<len; ++i){
            curChar = s[i];
            
            if(Char.IsDigit(curChar)){
                curNum = (curNum * 10) + (curChar - '0');
            }
            
            if(!Char.IsDigit(curChar) && !Char.IsWhiteSpace(curChar) || i==len-1){
                if(operation == '+'){
                    st.Push(curNum);
                }
                else if(operation == '-'){
                    st.Push(-curNum);
                }
                //곱, 나누기는 먼저 계산해서 나중에 더하기만 하도록 함.
                else if(operation == '*'){
                    int top = st.Pop();
                    st.Push(top * curNum);
                }
                else if(operation == '/'){
                    int top = st.Pop();
                    st.Push(top / curNum);
                }
                
                operation = curChar;
                curNum = 0;
            }
        }
        
        while(st.Count > 0){
            ans += st.Pop();
        }
        
        return ans;
    }
}
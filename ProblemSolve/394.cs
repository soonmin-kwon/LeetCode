/*****************
 * Decode String *
 *****************/

public class Solution {
    public string DecodeString(string s) {
        Stack<char> st = new Stack<char>();
        int len = s.Length;
        
        for(int i=0; i<len; ++i){
            if(s[i] != ']'){
                st.Push(s[i]);
            }
            else{
                string block = "";
                
                while(st.Peek() != '['){
                    block = st.Peek().ToString() + block;
                    st.Pop();
                }
                
                st.Pop();
                string num = "";
                
                while(st.Count != 0 && char.IsDigit(st.Peek())){
                    num = st.Peek().ToString() + num;
                    st.Pop();
                }
                
                int times = Int32.Parse(num);
                
                while(times > 0){
                    --times;
                    for(int j=0; j<block.Length; ++j){
                        st.Push(block[j]);
                    }
                }
            }
        }
        
        string ans = "";
        
        while(st.Count != 0){
            ans = st.Peek().ToString() + ans;
            st.Pop();
        }
        
        return ans;
    }
}
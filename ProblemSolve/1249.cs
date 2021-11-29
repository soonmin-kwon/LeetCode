/********************************************
 * Minimum Remove to Make Valid Parentheses *
 ********************************************/

public class Solution {
    public string MinRemoveToMakeValid(string s) {
        Stack<int> st = new Stack<int>();
        StringBuilder ans = new StringBuilder();
        int idx = 0;
        
        //모든 char을 돌면서 지워야 하는 괄호의 idx만 스택에 남긴다
        //ans에 하나씩 추가하면서 진행하기 때문에 ans를 기준으로 idx를 체크한다.
        foreach(char ch in s){
            if(ch == '('){
                ans.Append(ch);
                st.Push(idx++);
            }
            else if(ch == ')'){
                if(st.Any()){
                    ans.Append(ch);
                    st.Pop();
                    ++idx;
                }
            }
            else{
                ans.Append(ch);
                ++idx;
            }
        }        
        
        //여는 괄호가 남아있는 경우 지워준다.
        while(st.Any()){
            idx = st.Pop();
            ans.Remove(idx, 1);
        }
        
        return ans.ToString();
    }
}
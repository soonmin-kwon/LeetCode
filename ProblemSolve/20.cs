public class Solution {
    public bool CheckOpenBracket(char bracket){
        if(bracket == '(' || bracket == '[' || bracket == '{') {
            return true;
        }
        
        return false;
    }
    
    public bool CheckBracketsValid(char open, char close){
        if(open == '(' && close == ')' ||
           open == '[' && close == ']' ||
           open == '{' && close == '}')
            return true;
        
        return false;
    }
    
    public bool IsValid(string s) {
        if(s.Length == 1){
            return false;
        }
        
        Stack<char> stack = new Stack<char>();
        
        for(int i=0; i<s.Length; ++i){
            if(CheckOpenBracket(s[i])){
                stack.Push(s[i]);
            }
            else{
                if(stack.Count == 0)
                    return false;
                
                char top = stack.Pop();
                
                if(!CheckBracketsValid(top, s[i]))
                    return false;
            }
        }
        
        if(stack.Count != 0)
            return false;
        
        return true;
    }
}
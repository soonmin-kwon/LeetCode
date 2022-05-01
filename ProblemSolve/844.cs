/****************************
 * Backspace String Compare *
 ****************************/

public class Solution {
    public bool BackspaceCompare(string s, string t) {
        string modifiedS = BuildString(s);
        string modifiedT = BuildString(t);
        
        return modifiedS == modifiedT;
    }
    
    private string BuildString(string s){
        StringBuilder builder = new StringBuilder();
        
        for(int i=0; i<s.Length; ++i){
            if(s[i] != '#'){
                builder.Append(s[i]);
            }
            else if(builder.Length > 0){
                builder.Remove(builder.Length - 1, 1);
            }
        }
        
        return builder.ToString();
    }
}
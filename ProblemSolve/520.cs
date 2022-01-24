/******************
 * Detect Capital *
 ******************/

public class Solution {
    public bool DetectCapitalUse(string word) {
        if(word.Length == 1){
            return true;
        }
        
        bool isFirstCharCapital = Char.IsUpper(word[0]);
        
        if(isFirstCharCapital){
            bool hasSameCase = Char.IsUpper(word[1]);
            for(int i=1; i<word.Length; ++i){
                if(hasSameCase != Char.IsUpper(word[i])){
                    return false;
                }
            }
        }
        else{
            for(int i=1; i<word.Length; ++i){
                if(Char.IsUpper(word[i])){
                    return false;
                }
            }
        }
        
        return true;
    }
}
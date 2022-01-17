/****************
 * Word Pattern *
 ****************/

public class Solution {
    public bool WordPattern(string pattern, string s) {
        Dictionary<char, string> hash = new Dictionary<char, string>();
        Dictionary<string, char> hash2 = new Dictionary<string, char>();
        string[] splitted = s.Split(" ");
        
        if(pattern.Length != splitted.Length){
            return false;
        }
        
        for(int i=0; i<splitted.Length; ++i){
            if(hash.ContainsKey(pattern[i]) == true){
                if(hash[pattern[i]].Equals(splitted[i]) == false){
                    return false;
                }
            }
            else{
                hash.Add(pattern[i], splitted[i]);
            }
            
            if(hash2.ContainsKey(splitted[i]) == true){
                if(hash2[splitted[i]].Equals(pattern[i]) == false){
                    return false;
                }
            }
            else{
                hash2.Add(splitted[i], pattern[i]);
            }
        }
        
        return true;
    }
}
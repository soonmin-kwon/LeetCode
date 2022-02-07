/***********************
 * Find the Difference *
 ***********************/

public class Solution {
    public char FindTheDifference(string s, string t) {
        Dictionary<char, int> hash = new Dictionary<char, int>();
        
        foreach(char c in s){
            if(!hash.ContainsKey(c)){
                hash.Add(c, 1);
            }
            else{
                hash[c]++;
            }
        }
        
        foreach(char c in t){
            if(!hash.ContainsKey(c)){
                return c;
            }
            else{
                hash[c]--;
                if(hash[c] < 0){
                    return c;
                }
            }                        
        }
        
        return ' ';
    }
}
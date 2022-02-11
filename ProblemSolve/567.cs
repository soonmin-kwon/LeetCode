/*************************
 * Permutation in String *
 *************************/

public class Solution {
    public bool CheckInclusion(string s1, string s2) {
        if(s1.Length > s2.Length){
            return false;
        }
        
        int[] charCount = new int[26];
        int[] charCountInWindow = new int[26];
        
        Dictionary<char, int> hash = new Dictionary<char, int>();
        
        foreach(char c in s1){
            charCount[c - 'a']++;
        }
        
        for(int i=0; i<s2.Length; ++i){
            charCountInWindow[s2[i] - 'a']++;
            
            if(i >= s1.Length){
                charCountInWindow[s2[i-s1.Length] - 'a']--;
            }
            
            if(charCount.SequenceEqual(charCountInWindow)){
                return true;
            }
        }
        
        return false;
    }
}
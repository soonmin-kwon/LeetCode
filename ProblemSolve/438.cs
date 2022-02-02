/*********************************
 * Find All Anagrams in a String *
 *********************************/

public class Solution {
    public IList<int> FindAnagrams(string s, string p) {
        int[] charCount = new int[26];
        int[] window = new int[26];
        List<int> ans = new List<int>();
        
        foreach(char ch in p){
            charCount[ch - 'a']++;
        }
        
        for(int i=0; i<s.Length; ++i){
            window[s[i] - 'a']++;
            
            if(i >= p.Length){
                window[s[i-p.Length] - 'a']--;
            }
            
            if(charCount.SequenceEqual(window)){
                ans.Add(i-p.Length + 1);
            }
        }
        
        return ans;
    }
}
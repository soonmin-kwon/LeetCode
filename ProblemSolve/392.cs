/******************
 * Is Subsequence *
 ******************/

public class Solution {
    public bool IsSubsequence(string s, string t) {
        int idxS = 0;
        int idxT = 0;
        
        if(s.Length > t.Length){
            return false;
        }
        
        while(idxS < s.Length && idxT < t.Length){
            while(idxT < t.Length && t[idxT] != s[idxS]){
                idxT++;
            }
            
            if(idxT >= t.Length && idxS < s.Length){
                return false;
            }
            
            if(t[idxT] == s[idxS]){
                idxS++;
                idxT++;
            }
            
        }
        if(idxT >= t.Length && idxS < s.Length){
            return false;
        }
        
        return true;
    }
}
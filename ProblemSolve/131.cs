/***************************
 * Palindrome Partitioning *
 ***************************/

public class Solution {
    public bool IsPalindrome(ref string s, int start, int end){
        while(start < end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        
        return true;
    }
    
    //모든 partition 경우의 수 탐색
    public void Backtracking(ref List<IList<string>> ans, ref List<string> cur, ref string s, int start){
        if(start >= s.Length){
            ans.Add(new List<string>(cur));
            return;
        }
        
        for(int i=start; i<s.Length; ++i){
            if(IsPalindrome(ref s, start, i) == true){
                cur.Add(s.Substring(start, i-start+1));
                Backtracking(ref ans, ref cur, ref s, i+1);
                cur.RemoveAt(cur.Count -1);
            }
        }
        
        return;
    }
    
    public IList<IList<string>> Partition(string s) {
        List<IList<string>> ans = new List<IList<string>>();
        List<string> cur = new List<string>();
        
        Backtracking(ref ans, ref cur, ref s, 0);
        
        return ans;
    }
}
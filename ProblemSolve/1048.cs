/************************
 * Longest String Chain *
 ************************/

public class Solution {
    public int LongestStrChain(string[] words) {
        int ans = 1;
        Dictionary<string, int> dp = new Dictionary<string, int>();
        Array.Sort(words, (a, b) => {return a.Length < b.Length ? -1 : 1;});
        
        foreach(string word in words){
            if(!dp.ContainsKey(word)){
                dp.Add(word, 1);
            }
            
            for(int i=0; i<word.Length; ++i){
                string key = word.Substring(0, i) + word.Substring(i+1);
            
                if(dp.ContainsKey(key)){
                    dp[word] = dp[key] + 1;
                    ans = Math.Max(ans, dp[word]);
                }
            }
        }
        
        return ans;
    }
}
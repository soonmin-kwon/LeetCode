/**************************************************
 * Longest Substring Without Repeating Characters *
 **************************************************/

public class Solution {
    public int LengthOfLongestSubstring(string s) {
        int len = s.Length;
        
        if(len == 0){
            return 0;
        }
        
        int[] character = new int[128];  //hash
        int left = 0;
        int right = 0;
        int ans = 0;
        
        while(right < len){
            character[(int)s[right]]++;
            
            while(character[(int)s[right]] > 1){
                character[(int)s[left++]] -= 1;            
            }
            
            ans = Math.Max(ans, right - left + 1);
            right++;
        }
        
        return ans;
    }
}
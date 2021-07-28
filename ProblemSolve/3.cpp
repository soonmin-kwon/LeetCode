/**************************************************
 * Longest Substring Without Repeating Characters *
 **************************************************/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        
        if(len == 0){
            return 0;
        }
        
        int character[128] = {0, };
        int left = 0, right =0, ans = 0;
        
        while(right < len){
            character[s[right]]++;
            
            //중복
            /*
            abcabcbb
            
            c[a] = 1, l = 0, r = 0, ans = 1;
            c[b] = 1, l = 0, r = 1, ans = 2;
            c[c] = 1, l = 0, r = 2, ans = 3;
            c[a] = 2, l = 1, r = 3, ans = 3;
            c[b] = 2, l = 2, r = 4, ans = 3;
            c[c] = 2, l = 3, r = 5, ans = 3;
            c[b] = 2, l = 4, r = 6, ans = 3;
            c[b] = 2, l = 5, r = 7, ans = 3;
            */
            while(character[s[right]] > 1){
                character[s[left]] -= 1;
                left++;
            }
            
            ans = max(ans, right - left + 1);
            right++;
        }
        
        return ans;
    }
};
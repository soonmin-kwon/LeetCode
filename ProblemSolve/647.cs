/**************************
 * Palindromic Substrings *
 **************************/

public class Solution {
    public int CountSubstrings(string s) {
        int mid = 0, left = 0, right = 0, ans = 0, len = s.Length;
        
        for(int i=0; i<len; ++i){
            ans++;
            mid = i;
            left = mid - 1;
            right = mid + 1;
            
            while(left >= 0 && right < len){
                if(s[left] == s[right]){
                    ans++;
                    left--;
                    right++;
                }
                else{
                    break;
                }
            }
            
            if(i < len - 1 && s[i] == s[i+1]){
                left = mid - 1;
                right = mid + 2;
                ans++;
                
                while(left >= 0 && right < len){
                    if(s[left] == s[right]){
                        ans++;
                        left--;
                        right++;
                    }
                    else{
                        break;
                    }
                }                
            }
        }
        
        return ans;
    }
}
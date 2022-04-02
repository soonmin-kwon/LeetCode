/***********************
 * Valid Palindrome II *
 ***********************/

public class Solution {
    public bool isValidPalindrome(string s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
    
    public bool ValidPalindrome(string s) {
        int left = 0, right = s.Length - 1;
        
        while(left < right){
            if(s[left] != s[right]){
                return isValidPalindrome(s, left, right-1) || isValidPalindrome(s, left + 1, right);
            }
            
            left++;
            right--;
        }
        
        return true;
    }
}
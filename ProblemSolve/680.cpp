/***********************
 * Valid Palindrome II *
 ***********************/

class Solution {
public:
    bool isValidPalindrome(string s, int left, int right){
        while(left < right){
            if(s[left++] != s[right--]){
                return false;
            }
        }
        
        return true;
    }
    
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        
        while(left < right){
            if(s[left++] != s[right--]){
                return isValidPalindrome(s, left, right+1) || isValidPalindrome(s, left-1, right);
            }
        }
        
        return true;
    }
};
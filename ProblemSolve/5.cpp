/*********************************
 * Longest Palindromic Substring *
 *********************************/

// 참고 : https://www.crocus.co.kr/1075
// Manacher 알고리즘

class Solution {
public:
    string longestPalindrome(string s) {
        string temp = "";
        string ans ="";
        int len = s.size();        
        if(len == 1){
            return s;
        }
        
        for(int i=0; i<len; i++){
            temp += '@';
            temp += s[i];
        }
        temp += '@';
                
        int len2 = 2*len + 1;
        int radi = 0, center = 0;
        int maxRadi = 0, idx = 0;
        int* palindrome = new int[len2];
        
        for(int i=0; i<len2; i++){
            if( i< radi){
                palindrome[i] = min(palindrome[2*center - i], radi - i);
            }
            else{
                palindrome[i] = 1;
            }
            
            while(i - palindrome[i] >= 0 &&
                  i + palindrome[i] < len2 &&
                  temp[i - palindrome[i]] == temp[i + palindrome[i]]){
                
                palindrome[i]++;
            }
            
            if( radi < i + palindrome[i]){
                radi = i + palindrome[i];
                center = i;
            }                        
        }                
        
        for(int i=0; i<len2; i++){
            if(maxRadi < palindrome[i]){
                maxRadi = palindrome[i];
                idx = i;
            }
        }

        maxRadi -=1;
        
        for(int i = idx - maxRadi; i <= idx + maxRadi; i++){
            if(temp[i] != '@'){
                ans += temp[i];
            }
        }
        
        return ans;
    }
};
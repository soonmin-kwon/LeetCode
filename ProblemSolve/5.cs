/*********************************
 * Longest Palindromic Substring *
 *********************************/

public class Solution {    
    //Manacher 알고리즘
    // 참고 : https://www.crocus.co.kr/1075
    public string LongestPalindrome(string s) {
        string longS = "";
        string ans = "";
        
        int len = s.Length;
        
        if(len == 1){
            return s;
        }
        
        for(int i=0; i<len; ++i){
            longS += '@';
            longS += s[i];
        }
        
        longS += '@';
        
        len = longS.Length;
        int radius = 0, center = 0, maxRadius = 0, idx = 0;
        int[] palindromeSize = new int[len];
        
        for(int i=0; i<len; ++i){
            if(i < radius){
                palindromeSize[i] = Math.Min(palindromeSize[2*center -i], radius - i);
            }
            else{
                palindromeSize[i] = 1;
            }
            
            while(i - palindromeSize[i] >= 0 &&
                  i + palindromeSize[i] < len &&
                  longS[i - palindromeSize[i]] == longS[i + palindromeSize[i]]){
                palindromeSize[i]++;
            }
            
            if(radius < i + palindromeSize[i]){
                radius = i + palindromeSize[i];
                center = i;
            }
            
            if(maxRadius < palindromeSize[i]){
                maxRadius = palindromeSize[i];
                idx = i;
            }
        }
        
        maxRadius--;
        
        for(int i=idx - maxRadius; i<= idx + maxRadius; ++i){
            if(longS[i] != '@'){
                ans += longS[i];
            }
        }
        
        return ans;
    }
}
/********************
 * Valid Palindrome *
 ********************/

class Solution {
public:
    bool checkDigit(char c){
        if(c - '0' >= 0 && c - '0' <= 9){
            return true;
        }
        
        return false;
    }
    
    bool isPalindrome(string s) {
        int len = s.size();
        int left = 0;
        int right = len -1;
        
        //전부 소문자로 변환
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        //양 끝에서 하나씩 비교, 숫자와 영문자가 아니면 스킵
        while(left < right){
            if((s[left] < 97 || s[left] > 122) && !checkDigit(s[left])){
                left++;
                continue;
            }
            
            if((s[right] < 97 || s[right] > 122) && !checkDigit(s[right])){
                right--;
                continue;
            }
            
            if(s[left] == s[right]){
                left++;
                right--;
                continue;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};
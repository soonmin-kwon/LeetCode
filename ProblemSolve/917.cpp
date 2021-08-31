/************************
 * Reverse Only Letters *
 ************************/

class Solution {
public:
    //대문자, 소문자 알파벳에 속하는지 확인
    bool isChar(char c) {
        if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
            return true;
        }
        
        return false;
    }
    
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.size() - 1;
        
        //two pointers
        while(left < right){
            //두 pointer에 해당하는 값 모두 문자열이면 swap
            if(isChar(s[left]) && isChar(s[right])){
                swap(s[left], s[right]);
                left++;
                right--;
                continue;
            }
            
            //left pointer 값이 알파벳이 아니면 left pointer를 움직인다
            if(!isChar(s[left])){
                left++;
            }
            
            //right pointer 값이 알파벳이 아니면 right pointer를 움직인다
            if(!isChar(s[right])){
                right--;
            }
        }
        
        return s;
    }
};
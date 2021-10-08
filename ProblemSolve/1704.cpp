/****************************************
 * Determine if String Halves Are Alike *
 ****************************************/

class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' ||
           ch == 'I' || ch == 'i' || ch == 'O' || ch == 'o' ||
           ch == 'U' || ch == 'u'){
            return true;
        }
        
        return false;
    }
    bool halvesAreAlike(string s) {
        int vowelOfFirstHalf = 0;           //문자열 앞쪽의 자음 개수
        int vowelOfSecondHalf = 0;          //문자열 뒤쪽의 자음 개수
        
        
        //절반씩 for문 돌면서 확인한다
        //앞쪽 절반
        for(int i=0; i<s.size()/2; i++){
            if(isVowel(s[i])){
                vowelOfFirstHalf++;
            }
        }
        
        //뒤쪽 절반
        for(int i = s.size()/2; i<s.size(); i++){
            if(isVowel(s[i])){
                vowelOfSecondHalf++;
            }
        }
        
        return vowelOfFirstHalf == vowelOfSecondHalf;
    }
};
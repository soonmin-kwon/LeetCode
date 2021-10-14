/******************
 * Detect Capital *
 ******************/

class Solution {
public:
    bool detectCapitalUse(string word) {
        //첫 글자의 대소문자 여부
        bool isFirstUpper = isupper(word[0]);
        
        bool isAllUpper = true;
        bool isAllLower = true;
        
        //1번째부터 확인하면서 전부 소문자인지, 대문자인지 확인
        for(int i=1; i<word.size(); i++){
            //하나라도 대문자이면 모두 대문자여야만 한다
            if(isupper(word[i])){
                isAllLower = false;
            }
            //반대로 모두 소문자여야만 한다
            else{
                isAllUpper = false;
            }
        }
        
        //첫 글자가 대문자이면서 모두 대문자이면 true
        //첫 글자가 대문자인지 아닌지 상관 없고 나머지 문자열이 전부 소문자이면 true
        return (isFirstUpper && isAllUpper) || isAllLower;
    }
};
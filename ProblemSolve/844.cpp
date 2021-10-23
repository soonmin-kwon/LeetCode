/****************************
 * Backspace String Compare *
 ****************************/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        //backsapce를 다 한 뒤 결과물들
        string sAfter = "", tAfter = "";
        
        //s와 t에 #가 있으면 backspace를 해야한다.
        //비어있는 상태에서 backspace를 눌러봐야 아무일도 일어나지 않는다
        //비어있지 않은 상태에서 backspace를 누를 때 맨 뒤에 character를 지워준다
        //s 실행
        for(char ch : s){
            //backsapce를 할 때 sAfter가 비어있으면 그대로 둔다.
            if(ch == '#' && !sAfter.empty()){
                sAfter.pop_back();
            }
            else if(ch != '#'){
                sAfter += ch;
            }                        
        }
        //t실행
        for(char ch : t){
            if(ch == '#' && !tAfter.empty()){
                tAfter.pop_back();
            }
            else if(ch != '#'){
                tAfter += ch;
            }             
        }
        //둘이 같은지 확인
        return sAfter == tAfter;
    }
};
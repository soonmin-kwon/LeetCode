/********************************************
 * Number of Different Integers in a String *
 ********************************************/

class Solution {
public:
    int numDifferentIntegers(string word) {
        //중복 방지 : set
        set<string> s;                
        int len = word.size();
        
        int start = -1;
        int end = -1;
        
        string temp = "";
        
        //모든 문자열 순회
        for(int i=0; i<len; i++){
            //숫자가 나올 경우
            if(word[i] - '0' >=0 && word[i] - '0' <= 9){
                //start가 바뀌지 않은 경우 start 지정
                if(start == -1){
                    start = i;
                    continue;
                }
            }
            //일반 알파벳이 나올 경우
            else{
                //이미 숫자가 나온 경우
                if(start != -1){
                    //이전 값이 숫자이다
                    end = i -1;
                    
                    //맨 앞이 0이면 0이 나오지 않을 때 까지 스킵
                    while(word[start] == '0'){
                        start++;
                    }
                
                    //정답 문자열 생성
                    for(int i=start; i<=end; i++){
                        temp += word[i];
                    }
                
                    //set에 삽입
                    s.insert(temp);
                    //초기화
                    temp = "";
                    start = -1;
                    end = -1;
                }
            }                        
        }
        
        //마지막 문자열 그룹이 숫자로 끝날경우
        if(start != -1){
            while(word[start] == '0'){
                start++;
            }
            
            for(int i = start; i<len; i++){
                temp += word[i];
            }
            
            s.insert(temp);
        }        
        
        return s.size();
    }
};
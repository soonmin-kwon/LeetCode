/****************************
 * String to Integer (atoi) *
 ****************************/

class Solution {
public:
    //범위 안에 들어오는지 확인하는 함수
    int checkRange(string s, int sign){
        //10억 자리수보다 작으면 바로 리턴
        if(s.size() < 10){
            return sign * stoi(s);
        }
        //10억 자리수보다 크면 바로 리턴
        else if(s.size() > 10){
            if(sign == -1){
                return -2147483648;
            }
            else{
                return 2147483647;
            }                        
        }
        //10자리수 일때
        else{        
            //부호에 맞춰서 확인
            if(sign == -1){
                string minCheck = "2147483648";
                //제일 큰 자리수부터 확인하면서 인풋 스트링이 더 크면 바로 리턴
                for(int i=0; i<10; i++){
                    if(s[i] < minCheck[i]){
                        return sign * stoi(s);
                    }
                    else if( s[i] > minCheck[i]){
                        return -2147483648;
                    }
                }    
                //같으면 MIN값 리턴
                return -2147483648;
            }
            //위의 sign == -1일 때와 같은 방식으로 체크
            else{
                string maxCheck = "2147483647";
                for(int i=0; i<10; i++){
                    if(s[i] < maxCheck[i]){
                        return sign * stoi(s);
                    }
                    else if( s[i] > maxCheck[i]){
                        return 2147483647;
                    }
                }                  
                return 2147483647;
            }            
        }
        
        return sign * stoi(s) ;
    }
    
    int myAtoi(string s) {
        string temp ="";
        int len = s.size();
        int idx = 0;
        int sign = 1;
        
        //첫 character가 뭔지 찾기
        //공백은 스킵, +,-나오면 다음 자리수 확인, 숫자가 아닌 알파벳 나오면 바로 리턴
        //숫자가 나오면 break;
        for(;idx<len; idx++) {
            if(s[idx] == ' ') {
                continue;
            }
            else if(s[idx] == '-') {
                sign = -1;
                idx++;
                break;
            }
            else if(s[idx] == '+') {
                idx++;
                break;
            }
            else if(s[idx] -'0' < 0 || s[idx] - '0' > 9) {
                return 0;
            }
            else {
                break;
            }            
        }
                
        //위에서 유요한 첫 character를 찾았고 idx부터 확인        
        while(temp.size() == 0 && idx < len) {
            //비어있는 상태에서 0이 들어오면 더하지 않음
            //0이 들어오지 않으면 바로 break;
            if(s[idx] -'0' >= 1 && s[idx] - '0' <= 9){
                temp += s[idx];
                idx++;
                break;
            }
            else if(s[idx] - '0' < 0 || s[idx] - '0' > 9 ){
                break;
            }
            idx++;
        }
        
        //위에서 첫 숫자를 찾았고 뒤에 붙을 숫자를 찾는다.
        for(; idx<len; idx++){
            if(s[idx] -'0' >= 0 && s[idx] - '0' <= 9){
                temp += s[idx];
            }
            //숫자가 아니면 바로 break;
            else{
                break;
            }
        }

        //새로 만든 스트링의 길이가 0이면 return 0;
        if(temp.size() == 0){
            return 0;
        }
        
        return checkRange(temp, sign);
    }
};
/****************************
 * Excel Sheet Column Title *
 ****************************/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        int temp;
        
        //제일 뒷 자리부터 계산
        while(columnNumber){
            temp = columnNumber % 26;
            
            //temp==0이면 Z추가
            if(temp == 0){
                ans = 'Z' + ans;
                columnNumber /= 26;
                //26으로 나눠떨어지면 위 연산을 하면 1이 남는다
                columnNumber--;                
            }
            else{                
                ans = (char)(temp - 1 + 'A') + ans;
                columnNumber /= 26;
            }
        }        
        
        return ans;
    }
};
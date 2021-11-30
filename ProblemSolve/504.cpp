/**********
 * Base 7 *
 **********/

class Solution {
public:
    string convertToBase7(int num) {
        //주어진 num이 정답
        if(num >= -6 && num <= 6){
            return to_string(num);
        }
        
        string ans = "";
        int maxSevenPow = (int)pow(7,8);
        
        //음수 처리
        if(num < 0){
            num *= -1;
            ans += '-';
        }
        
        //주어진 num에 맞게 maxSevenPow 조정
        while(maxSevenPow > num){
            maxSevenPow /= 7;
        }
        
        //제일 앞의 bit부터 채워나간다.
        while(num){
            ans += (char)((num / maxSevenPow) + '0');
            num %= maxSevenPow;
            maxSevenPow /= 7;
        }
        
        //남은 bit 채우기
        while(maxSevenPow){
            ans += '0';
            maxSevenPow /= 7;
        }
        
        return ans;
    }
};
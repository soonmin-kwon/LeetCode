/**********
 * Base 7 *
 **********/

public class Solution {
    public string ConvertToBase7(int num) {
        //굳이 따로 구하지 않아도 되는 경우
        if(num < 7 && num >= 0){
            return num.ToString();
        }
        
        //될 수 있는 가장 큰 자리수의 bit부터 채운다
        int maxSevenPow = (int)Math.Pow(7.0,8.0);
        StringBuilder ans = new StringBuilder();
        
        //음수면 양수로 바꿔서 7진수로 바꾸고 -를 붙인다
        if(num < 0){
            num *= -1;
            ans.Append('-');
        }
        
        //주어진 수에 맞는 제일 큰 거듭제곱의 수를 구한다
        while(maxSevenPow > num){
            maxSevenPow /= 7;
        }
        
        //제일 앞의 bit부터 채워나간다
        while(num != 0){
            ans.Append(num / maxSevenPow);
            num %= maxSevenPow;
            maxSevenPow /= 7;
        }
        
        //나머지 bit를 0으로 채운다
        while(maxSevenPow != 0){
            ans.Append(0);
            maxSevenPow /= 7;
        }
        
        return ans.ToString();        
    }
}
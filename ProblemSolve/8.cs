/****************************
 * String to Integer (atoi) *
 ****************************/

public class Solution {
    public int MyAtoi(string s) {
        int len = s.Length;
        int idx = 0, ans = 0, sign = 1;
        
        //공백 스킵
        while(idx < len && Char.IsWhiteSpace(s[idx])){
            ++idx;
        }
        
        //부호 확인
        if(idx < len && s[idx] == '-'){
            sign = -1;
            ++idx;
        }
        else if(idx < len && s[idx] == '+'){
            ++idx;
        }
        
        //숫자면 누적 계산
        while(idx < len && Char.IsDigit(s[idx])){
            var digit = s[idx] - '0';
            
            //overflow인 경우 체크
            if((ans > Int32.MaxValue / 10) || (ans == Int32.MaxValue / 10 && digit > Int32.MaxValue % 10)){
                return sign == 1 ? Int32.MaxValue : Int32.MinValue;
            }
            
            ans *= 10;
            ans += digit;
            
            ++idx;
        }
        
        return ans * sign;
    }
}
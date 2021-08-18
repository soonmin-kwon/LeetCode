/***************
 * Decode Ways *
 ***************/

class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        
        if(s[0] == '0'){
            return 0;
        }
        
        if(len == 1){
            return 1;
        }        
        
        int tens, units, sum;
        //배열 생성, 초기화
        int* dp = new int[len+1];
        memset(dp, 0, (len+1) * sizeof(int));
        
        dp[0] = 1;
        dp[1] = 1;
        
        //dp[i]는 s[i-1]에 매칭
        for(int i=2; i<=len; i++){
            //10의 자리수, 1의 자리수 찾고 계산
            tens = s[i-2] - '0';
            units = s[i-1] - '0';
            sum = tens * 10 + units;
            
            //1의 자리가 0일 경우
            if(units == 0){
                //범위를 벗어나거나 0이 두 개이상 붙어있으면 decoding할 수 없음
                if(sum > 26 || sum == 0){
                    return 0;
                }
                
                //무조건 두자리수여야 하므로 두칸 앞에 있는 dp값을 받는다
                //바로 한 칸 앞을 받으려면 1의 자리수가 스스로 decoding가능한 수여야 한다
                dp[i] = dp[i-2];
            }
            //무조건 한 자리수의 경우만 가능한 경우이므로 한 칸 앞의 경우의 수를 그대로 받는다
            else if(tens == 0 || sum > 26){
                dp[i] = dp[i-1];
            }
            //한 자리수도 가능하고 두 자리수도 가능한 경우 두 자리수로 선택했을 경우와 한 자리수를 선택했을 경우의 수를 모두 받는다
            else{
                dp[i] = dp[i-2] + dp[i-1];
            }
                        
        }
                
        return dp[len];
    }
};
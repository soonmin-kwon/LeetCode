/********************
 * Fibonacci Number *
 ********************/

class Solution {
public:
    //피보나치 수열의 n번째 값 리턴
    int fib(int n) {
        vector<int> dp(n + 1);
        
        //n이 1이하일 경우에는 n값이 피보나치 수열의 값
        if(n <= 1){
            return n;
        }
        
        //초기작업
        dp[0] = 0;
        dp[1] = 1;
        
        //F(n) = F(n - 1) + F(n - 2), n > 1
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-2] + dp[i-1];
        }
        
        return dp[n];
    }
};
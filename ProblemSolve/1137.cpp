/**************************
 * N-th Tribonacci Number *
 **************************/

class Solution {
public:
    int tribonacci(int n) {
        if(n <=1){
            return n;
        }
        
        vector<int> dp(n + 1);
        
        //T0 = 0, T1 = 1, T2 = 1
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        
        //Tn+3 = Tn + Tn+1 + Tn+2, n >= 0
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        }
        
        return dp[n];
    }
};
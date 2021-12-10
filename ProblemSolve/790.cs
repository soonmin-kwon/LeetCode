/*****************************
 * Domino and Tromino Tiling *
 *****************************/

//참고 : https://leetcode.com/problems/domino-and-tromino-tiling/discuss/116581/Detail-and-explanation-of-O(n)-solution-why-dpn2*dn-1%2Bdpn-3
public class Solution {
    public int NumTilings(int n) {
        int mod = 1000000007;
        
        if(n < 3){
            return n;
        }
        
        long[] dp = new long[n + 1];
        
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        
        for(int i=4; i<=n; ++i){
            dp[i] = (2 * dp[i-1] + dp[i-3]) % mod;
        }
        
        return (int)dp[n];
    }
}
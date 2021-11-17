/****************
 * Unique Paths *
 ****************/

public class Solution {
    //(m+n-2)! / (m-1)!(n-1)!로도 구할 수 있는데 범위를 벗어남
    //DP로 풀이
    public int UniquePaths(int m, int n) {
        int[,] dp = new int[m,n];
        for(int i=0; i<m; ++i){
            dp[i,0] = 1;
        }
        
        for(int i=0; i<n; ++i){
            dp[0,i] = 1;
        }
        
        //dp[y,x]는 x,y번째 칸에 갈 수 있는 경로의 개수
        //dp[y,x]는 dp[y-1,x]에서 가거나, dp[y,x-1]에서 가야만 한다
        //그래서 두 경우의 수를 더해주면 dp[y,x]로 가는 경로의 개수가 된다
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                dp[i,j] = dp[i-1,j] + dp[i,j-1];
            }
        }
        
        return dp[m-1,n-1];
    }
}
/*******************
 * Perfect Squares *
 *******************/

class Solution {
public:
    //n을 제곱수의 더하기로 나타내야하는 문제이다
    //각 제곱수, 1, 4, 9 ... 등은 하나의 제곱수로 나타낼 수 있고
    //그 외 2, 6, 12 등은 이전 값들의 결과에 따라 바뀐다
    //dp[n]을 만들기 위해서는 dp[n - 1], dp[n - 4], dp[n - 9]... dp[n - k^2]의 값을 확인하면 된다
    //확인하는 값들에서는 한번에 dp[n]까지 도달할 수 있고 dp[n]까지 도달할 수 있는 모든 dp 배열 값중에서
    //가장 작은 수를 고르면 된다    
    int numSquares(int n) {
        //dp 배열
        vector<int> dp(n + 1, INT_MAX);
        //첫 square 값이 1이 되도록 0으로 설정
        dp[0] = 0;                
        
        for(int i=1; i<=n; i++){
            //현재 i에서 제곱수만큼 빼면서 가장 작은 수가 나오도록 한다
            for(int j=1; j*j<=i; j++){
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        
        return dp[n];
    }
};
/******************************
 * Unique Binary Search Trees *
 ******************************/

//참고 : https://suhak.tistory.com/77
//     : https://ko.wikipedia.org/wiki/%EC%B9%B4%ED%83%88%EB%9E%91_%EC%88%98

class Solution {
public:
    //카탈랑 수
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        
        for(int i=2; i<=n; i++){
            for(int j=1; j<=i; j++){
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        
        return dp[n];
    }
};
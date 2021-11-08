/******************************
 * Unique Binary Search Trees *
 ******************************/

//참고 : https://suhak.tistory.com/77
//     : https://ko.wikipedia.org/wiki/%EC%B9%B4%ED%83%88%EB%9E%91_%EC%88%98

public class Solution {
    //카탈랑 수
    public int NumTrees(int n) {
        int[] dp = new int[n + 1];
        
        dp[0] = dp[1] = 1;
        
        //n = 4일때
        //한 노드가 root, 나머지 3 노드가 child로 간다
        //0 root 3, 1 root 2, 2 root 1, 3 root 0 이렇게 모든 경우를 더하면 n = 4일때 tree의 개수를 구할 수 있다                
        for(int i=2; i<=n; i++){
            for(int j=1; j<=i; j++){
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        
        return dp[n];
    }
}
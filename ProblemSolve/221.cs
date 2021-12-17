/******************
 * Maximal Square *
 ******************/

public class Solution {
    public int MaximalSquare(char[][] matrix) {
        int lenRow = matrix.Length;
        int lenCol = matrix[0].Length;
        int ans = 0;
    
        int[,] dp = new int[lenRow + 1,lenCol + 1];
        //인접한 3곳의 값을 확인해 가장 작은 값에 + 1을 하면 만들 수 있는 정사각형의 한변의 길이가 된다.
        //ex) matrix ={{1, 1}, {1, 1}} -> dp = {{0, 0, 0}, {0, 1, 1}, {0, 1, 2}}
        for(int i=1; i<=lenRow; ++i){
            for(int j=1; j<=lenCol; ++j){
                if(matrix[i-1][j-1] == '1'){
                    dp[i,j] = Math.Min(dp[i-1,j], Math.Min(dp[i,j-1], dp[i-1,j-1])) + 1;
                }
                ans = Math.Max(ans, dp[i,j]);
            }
        }
        
        return ans * ans;
    }
}

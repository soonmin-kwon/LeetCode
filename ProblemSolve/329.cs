/***************************************
 * Longest Increasing Path in a Matrix *
 ***************************************/

public class Solution {
    int[] moveX = new int[4] {1, 0, -1, 0};
    int[] moveY = new int[4] {0, 1, 0, -1};
    
    public int DFS(ref int[][] matrix, ref int[,] dp, int row, int col){
        if(dp[row,col] != 1){
            return dp[row,col];
        }
        
        for(int i=0; i<4; ++i){
            int nextX = col + moveX[i];
            int nextY = row + moveY[i];
            
            if(nextX < 0 || nextX >= matrix[0].Length || nextY < 0 || nextY >= matrix.Length || matrix[nextY][nextX] <= matrix[row][col]) {
                continue;
            }
            
            dp[row,col] = Math.Max(dp[row,col], 1 + DFS(ref matrix, ref dp, nextY, nextX));
        }
        
        return dp[row,col];
    }
    
    public int LongestIncreasingPath(int[][] matrix) {
        int ans = 0;
        
        int[,] dp = new int[matrix.Length, matrix[0].Length];
        
        for(int i=0; i<matrix.Length; ++i){
            for(int j=0; j<matrix[i].Length; ++j){
                dp[i,j] = 1;
            }
        }
        
        for(int i=0; i<matrix.Length; ++i){
            for(int j=0; j<matrix[i].Length; ++j){
                ans = Math.Max(ans, DFS(ref matrix, ref dp, i, j));
            }
        }
        
        return ans;
    }
}
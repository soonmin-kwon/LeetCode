public class Solution {
    public bool SearchMatrix(int[][] matrix, int target) {
        int row = matrix.Length - 1;
        int col = matrix[0].Length - 1;
        
        int left = 0;
        while(left <= row && row >= 0){
            int mid = (left + row) / 2;
            if(matrix[mid][0] == target){
                return true;
            }
            else if(matrix[mid][0] > target){
                row = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        left = 0;
        
        while(left <= col && row >= 0){
            int mid = (left + col) / 2;
            if(matrix[row][mid] == target){
                return true;
            }
            else if(matrix[row][mid] > target){
                col = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        
        return row > 0 && col > 0 && target == matrix[row][col];
    }
}
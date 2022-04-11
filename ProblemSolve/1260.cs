/*****************
 * Shift 2D Grid *
 *****************/

public class Solution {
    public IList<IList<int>> ShiftGrid(int[][] grid, int k) {
        int row = grid.Length;
        int col = grid[0].Length;
        
        List<IList<int>> ans = new List<IList<int>>();
        
        for (int i = 0 ; i < row ; i++) { 
            ans.Add(new List<int>(new int[col]));
        }

        
        for(int i=0; i<row * col; ++i){
            int prevRow = i / col;
            int prevCol = i % col;
            int newRow = (prevRow + (prevCol + k) / col) % row;
            int newCol = (prevCol + k) % col;
            
            ans[newRow][newCol] = grid[prevRow][prevCol];
        }
        
        return ans;
    }
}
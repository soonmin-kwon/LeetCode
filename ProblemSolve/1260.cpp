/*****************
 * Shift 2D Grid *
 *****************/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> ans(row, vector<int>(col));
        
        for(int i=0; i<row * col; ++i){
            int prevRow = i / col;
            int prevCol = i % col;
            int newRow = (prevRow + (prevCol + k) / col) % row;
            int newCol = (prevCol + k) % col;
            
            ans[newRow][newCol] = grid[prevRow][prevCol];
        }
        
        return ans;
    }
};
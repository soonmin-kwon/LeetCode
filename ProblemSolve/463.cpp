/********************
 * Island Perimeter *
 ********************/

class Solution {
public:
    int mR[4] = {1, 0, -1, 0};
    int mC[4] = {0, 1, 0, -1};
    
    //현재 섬에서 계산할 수 있는 perimeter를 계산한다
    int calPerimeter(vector<vector<int>>& grid, int row, int col){
        int perimeter = 0;
        
        for(int i=0; i<4; i++){
            int nextRow = row + mR[i];
            int nextCol = col + mC[i];
            
            //범위를 넘어가면 벽에 막혀있는것이므로 perimeter++
            if(nextRow < 0 || nextRow >= grid.size() || nextCol < 0 || nextCol >= grid[0].size()){
                perimeter++;
                continue;
            }
            
            //물로 막혀있으면 perimeter++
            if(grid[nextRow][nextCol] == 0){
                perimeter++;
            }
        }
        
        return perimeter;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                //현재 좌표점이 땅이면 perimeter를 계산
                if(grid[i][j] == 1){
                    ans += calPerimeter(grid, i, j);
                }
            }
        }
        
        return ans;
    }
};
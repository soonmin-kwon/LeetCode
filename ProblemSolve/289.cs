/****************
 * Game of Life *
 ****************/

public class Solution {
    // 1. 주변에 live cell이 두 개 미만으로 있으면 live cell -> die
    // 2. 주변에 live cell이 두 개, 세 개 있으면 live cell -> live
    // 3. 주변에 live cell이 세 개 초과로 있으면 live cell - > die
    // 4. 주변에 live cell이 정확히 세 개 있으면 dead cell -> live
    public void GameOfLife(int[][] board) {
        int row = board.Length;
        int col = board[0].Length;
        int liveCellCount = 0;
        
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                liveCellCount = 0;
                
                for(int y = Math.Max(i-1, 0); y < Math.Min(i+2, row); ++y){
                    for(int x = Math.Max(j-1, 0); x < Math.Min(j+2, col); ++x){
                        if(y == i && x == j)
                            continue;
                        
                        if(board[y][x] == 1 || board[y][x] == 3){
                            liveCellCount++;
                        }
                    }
                }
                
                if(board[i][j] == 0){
                    if(liveCellCount == 3){
                        board[i][j] = 4;
                    }
                }
                else{
                    if(liveCellCount < 2 || liveCellCount > 3){
                        board[i][j] = 3;
                    }
                }
            }
        }
        
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                board[i][j] %= 3;
            }
        }
    }
}
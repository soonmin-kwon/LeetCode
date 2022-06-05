/***************
 * N-Queens II *
 ***************/

class Solution {
public:
    int ans = 0;
    
    bool checkCanPut(int col, int row, int n, vector<string>& chessBoard){
        for(int i=0; i<row; ++i){
            if(chessBoard[i][col] == 'Q'){
                return false;
            }
            
            for(int j=0; j<n; ++j){
                if(chessBoard[i][j] == 'Q' && abs(i-row) == abs(j-col)){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void nQueen(int n, int row, vector<string>& chessBoard){
        if(n == row){
            ans++;
            return;
        }
        
        for(int i=0; i<n; ++i){
            chessBoard[row][i] = 'Q';
            
            if(checkCanPut(i, row, n, chessBoard)){
                nQueen(n, row + 1, chessBoard);
            }
            
            chessBoard[row][i] = '.';
        }
    }
    
    int totalNQueens(int n) {
        if(n <= 3){
            if(n == 1){
                return 1;
            }
        }
        
        vector<string> chessBoard(n, string(n, '.'));
        
        nQueen(n, 0, chessBoard);
        
        return ans;
    }
};
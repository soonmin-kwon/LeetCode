/**********************
 * Surrounded Regions *
 **********************/

class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c){
        //범위를 벗어나거나 탐색하지 않는 지역 확인
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != 'O'){
            return;
        }
        //border에 연결된 O지역을 B로 바꿔서 마지막에 B를 O로 바꾸면 border와 연결된 지역은 O로 남아있게 된다
        board[r][c] = 'B';
        
        //DFS
        dfs(board, r - 1, c);
        dfs(board, r + 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
        
        return;
    }
    
    //border에 있는 O를 찾아서 그 O와 연결된 지역을 다른 값으로 수정한다
    //border와 연결되어 있지 않은 O영역은 X로 바뀌게 되고 다른 값으로 바뀐 영역을 다시 O로 돌리면
    //둘러싸인 영역만 뒤집는 것과 같다
    void solve(vector<vector<char>>& board) {
        int lenR = board.size();
        int lenC = board[0].size();
        
        //lenR, lenC둘 중 하나라도 길이가 2보다 작으면 무조건 border에 위치하게 된다
        if(lenR <= 2 || lenC <= 2){
            return;
        }
        
        //왼쪽, 오른쪽 모서리와 연결된 영역 확인
        for(int i=0; i<lenR; i++){
            if(board[i][0] == 'O'){
                dfs(board, i, 0);
            }
            
            if(board[i][lenC - 1] == 'O'){
                dfs(board, i, lenC - 1);
            }
        }
        
        //위에서 왼쪽, 오른쪽 모서리를 확인했으므로
        //위쪽, 아래쪽 모서리에서 확인하지 않은 부분만 확인
        for(int i=1; i<lenC - 1; i++){            
            if(board[0][i] == 'O'){
                dfs(board, 0, i);
            }
            
            if(board[lenR - 1][i] == 'O'){
                dfs(board, lenR - 1, i);
            }
        }
        
        //border와 연결된 영역인 B를 찾아서 O로 바꾸고
        //둘러싸인 O를 X로 바꿔 정답을 찾는다
        for(int i=0; i<lenR; i++){
            for(int j=0; j<lenC; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                
                if(board[i][j] == 'B'){
                    board[i][j] = 'O';
                }
            }
        }
        
        return;
    }
};
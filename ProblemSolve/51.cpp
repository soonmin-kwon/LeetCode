/************
 * N-Queens *
 ************/

class Solution {
public:    
    vector<vector<string>> ans;
    
    //check 함수 1
    //Queen을 현재 row, col에 놓아도 되는지 확인
    //현재점을 기준으로 같은 col, 좌상향 대각, 우상향 대각에 다른 Queen이 있는지 각각 확인
    bool check1(int col, int row, vector<string>& chess, int n){        
        //col 확인
        for(int i=0; i<row; i++){
            if((chess[i][col] == 'Q')){
                return false;
            }
        }
        
        //좌상향 대각에 있는지 확인
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if((chess[i][j] == 'Q')){
                return false;
            }
        }
        
        //우상향 대각에 있는지 확인
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if((chess[i][j] == 'Q')){
                return false;
            }
        }
        
        //어느 곳에도 속하지 않으면 Queen을 놓아도 된다
        return true;
    }    
    
    //check 함수 2
    //Queen을 현재 row, col에 놓아도 되는지 확인
    //현재점을 기준으로 같은 col에 Queen이 있는지 확인하고, 좌상향 대각, 우상향 대각에 다른 Queen이 있는지 기울기를 이용해 확인
    bool check(int col, int row, vector<string>& chess, int n){        
        for(int i=0; i<row; i++){
            //같은 col에 있는지 확인
            if((chess[i][col] == 'Q')){
                return false;
            }
            
            //대각선위에 있는지 확인
            for(int j=0; j<n; j++){
                //기울기 체크
                if(chess[i][j] == 'Q' && (abs(i - row) == abs(j - col))){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void nQueen(int n, int row, vector<string>& chess){
        //체스판의 마지막 row에 말을 놓았다면 정답 중 하나
        if(n == row){            
            ans.push_back(chess);
            return;
        }
        
        for(int i=0; i<n; i++){
            //현재 row, i에 Queen을 놓는다
            chess[row][i] = 'Q';
            //놓아도 되는지 확인하고
            if(check(i, row, chess, n)){
                nQueen(n, row+1, chess);
            }
            //원상복구
            chess[row][i] = '.';
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        //n이 2, 3일 경우에는 절대로 Queen을 n개 만큼 놓지 못한다
        if(n <= 3){
            //n이 1일 경우
            if(n == 1){
                return {{"Q"}};
            }
            return ans;
        }                
        
        //체스판 초기화
        vector<string> chess(n, string(n, '.'));
        nQueen(n, 0, chess);
        
        return ans;
    }
};
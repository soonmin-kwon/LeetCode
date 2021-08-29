/****************
 * Game of Life *
 ****************/

class Solution {
public:         
    /*
    조건

    1. 주변에 live cell이 두 개 미만으로 있으면, live cell -> die
    2. 주변에 live cell이 두 개, 세 개 있으면, live cell -> live
    3. 주변에 live cell이 세 개 초과로 있으면, live cell - > die
    4. 주변에 live cell이 정확히 세 개 있으면, dead cell -> live
    */
    void gameOfLife(vector<vector<int>>& board) {
        int len = board.size(); //y
        int len2 = board[0].size(); //x
        int count = 0;
        
        //모든 좌표 순회
        for(int i=0; i<len; i++){
            for(int j=0; j<len2; j++){
                count = 0;
                
                //각 좌표에서 8방향 탐색
                for(int y=max(i - 1, 0); y<min(i + 2, len); y++){
                    for(int x=max(j - 1, 0); x<min(j + 2, len2); x++){
                        if(y == i && x == j){
                            continue;
                        }
                        
                        //board[y][x]가 live cell인지 확인
                        //3은 원래는 1인 좌표
                        if(board[y][x] == 1 || board[y][x] == 3){
                            count++;
                        }
                    }
                }
                
                //4번 조건
                if(board[i][j] == 0){
                    if(count == 3){
                        board[i][j] = 4;
                    }
                }
                //1번, 3번 조건
                //2번 조건은 변화가 없기 때문에 체크하지 않는다
                else{
                    if(count < 2 || count > 3){
                        board[i][j] = 3;
                    }
                }                
            }
        }
        
        //위에서 임의로 변경한 값을 정답에서 요하는 값으로 바꾼다
        for(int i=0; i<len; i++){
            for(int j=0; j<len2; j++){
                //1번, 3번 조건은 dead cell로 바뀌어야하고
                //4번 조건은 live cell로 바뀌어야하므로
                //3 -> 0, 4 -> 1, 따라서 %= 3 연산을 한다
                board[i][j] %= 3;
            }
        }
    }
};
/***************
 * Word Search *
 ***************/

class Solution {
public:
    //board 벡터 경계값 저장
    int borderY;
    int borderX;
    //입력 단어 길이 저장
    int wordLen;
    
    bool patrol(vector<vector<char>>& board, int y, int x, string word, int curLen) {
        //지금 만든 단어의 길이가 입력 단어의 길이와 같으면 리턴
        if(curLen == wordLen){
            return true;
        }
       
        //경계 밖으로 나가거나, 다음에 나와야 하는 단어가 아니면 리턴
        if (x < 0 || x >= borderX || y < 0 || y >= borderY || board[y][x] != word[curLen]){
            return false;
        }
        
        //임시 값 저장
        char temp = board[y][x];
        
        //벡터 값 변경
        board[y][x] = '.';
        
        //동서남북으로 순회하면서 답을 찾는다, 하나라도 true가 나오면 true
        bool ans = patrol(board, y+1, x, word, curLen+1) || patrol(board, y-1, x, word, curLen+1) || 
                   patrol(board, y, x+1, word, curLen+1) || patrol(board, y, x-1, word, curLen+1);
        
        //벡터 값을 다시 원상복귀
        board[y][x] = temp;
        
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        wordLen = word.size();
        borderY = board.size();
        borderX = board[0].size();
        char start = word[0];
        
        for (int i = 0; i < borderY; i++) {
            for (int j = 0; j < borderX; j++) {            
                if (board[i][j] == start && patrol(board, i, j, word, 0)){
                    return true;
                }
            }
        }
        
        return false;
    }
};
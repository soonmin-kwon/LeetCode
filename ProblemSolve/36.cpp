/****************
 * Valid Sudoku *
 ****************/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, bool> mapR;
        unordered_map<int, bool> mapC;
        unordered_map<int, bool> mapB;
        
        for(int i=0; i<9; i++){
            //map 초기화
            mapR.clear();
            mapC.clear();
            mapB.clear();
            
            for(int j=0; j<9; j++){
                //box를 확인할 때 필요한 index
                /*
                 * 0 0, 0 1, 0 2, 1 0, 1 1, 1 2 ... 2 0, 2 1, 2 2
                 * 0 3, 0 4, 0 5 ...
                 * 위의 방식으로 진행
                 */
                int idx = i / 3 * 3 + j / 3;
                int idx2 = (i * 3) % 9 + j % 3;
                    
                //이미 map에 있는지 확인하고
                auto it1 = mapR.find(board[i][j]);
                auto it2 = mapC.find(board[j][i]);
                auto it3 = mapB.find(board[idx][idx2]);                                                    
                //없으면 map에 넣어주고
                if(it1 == mapR.end() && board[i][j] != '.'){                        
                    mapR[board[i][j]] = true;
                }
                    
                if(it2 == mapC.end() && board[j][i] != '.'){                    
                    mapC[board[j][i]] = true;
                }
                    
                if(it3 == mapB.end() && board[idx][idx2] != '.'){
                    mapB[board[idx][idx2]] = true;
                }
                    
                //이미 있으면 바로 false
                if(it1 != mapR.end() || it2 != mapC.end() || it3 != mapB.end()){
                    return false;
                }   
                
            }
        }
        
        return true;
    }
};
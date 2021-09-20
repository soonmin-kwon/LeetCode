/*************************************
 * Find Winner on a Tic Tac Toe Game *
 *************************************/

class Solution {
public:
    //map의 row, col, diagonal을 탐색하며 승자가 나오는지 확인한다
    string findWinner(vector<vector<char>>& map){
        //map의 row를 탐색한다
        for(int i=0; i<3; i++){
            //한 row가 전부 같은 값이면서 초기 값이 아닌 경우 승자가 있다
            if(map[i][0] == map[i][1] && map[i][1] == map[i][2] && map[i][0] != 0){
                //X로 같으면 A가 승자
                if(map[i][0] == 'X'){
                    return "A";
                }
                //O로 같으면 B가 승자
                else{
                    return "B";
                }
            }
        }
        
        //map의 col을 탐색한다
        for(int i=0; i<3; i++){
            //한 col이 전부 같은 값이면서 초기 값이 아닌 경우 승자가 있다
            if(map[0][i] == map[1][i] && map[1][i] == map[2][i] && map[0][i] != 0){
                //row의 케이스와 동일
                if(map[0][i] == 'X'){
                    return "A";
                }
                else{
                    return "B";
                }
            }
        }
        
        //왼쪽 위에서 오른쪽 아래로 진행하는 대각선을 확인한다
        //대각선이 모두 같은 값이면서 초기 값이 아닌 경우 승자가 있다
        if(map[0][0] == map[1][1] && map[1][1] == map[2][2] && map[0][0] != 0){
            if(map[0][0] == 'X'){
                return "A";
            }
            else{
                return "B";
            }
        }
        
        //오른쪽 위에서 왼쪽 아래로 진행하는 대각선을 확인한다
        //위와 동일하다
        if(map[0][2] == map[1][1] && map[1][1] == map[2][0] && map[0][2] != 0){
            if(map[0][2] == 'X'){
                return "A";
            }
            else{
                return "B";
            }
        }
        
        //승자가 없는 경우
        return "";
    }
    
    
    string tictactoe(vector<vector<int>>& moves) {
        //승자가 절대 나올 수 없는 경우
        if(moves.size() < 5){
            return "Pending";
        }
        
        //Tic Tac Toe 게임을 진행하는 Map
        vector<vector<char>> map(3, vector<char>(3));
        
        for(int i=0; i<moves.size(); i++){
            //A와 B가 순서대로 게임을 진행한다
            if(i % 2){
                map[moves[i][0]][moves[i][1]] = 'O';
            }
            else{
                map[moves[i][0]][moves[i][1]] = 'X';
            }
            
            //map을 살피면서 승자를 찾는다
            string temp = findWinner(map);
            
            //승자가 있는 경우 승자를 리턴한다
            if(temp != ""){
                return temp;
            }
        }
        
        //게임을 모두 진행했지만 위에서 승자가 없는 경우는 두 가지 경우이다
        
        //첫번째 : 승자가 누군지 모르는 경우
        //최대 9번 게임이 진행되는데 9번을 진행하지 않았다면 승자를 알 수 없는 경우이다
        if(moves.size() != 9){
            return "Pending";
        }
        
        //두번째 : 승자가 없는 경우
        //게임을 9번 모두 진행했지만 승자가 없는 경우는 비기는 경우이다
        return "Draw";
    }
};
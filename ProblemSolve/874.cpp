/****************************
 * Walking Robot Simulation *
 ****************************/

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        //장애물의 좌표값 저장
        unordered_set<string> obstaclesSet;
        
        //장애물의 좌표값을 string 형태로 변형해서 저장, 무한한 공간이기 때문에 int타입으로 표현하기 어렵다
        for(int i=0; i<obstacles.size(); i++){
            obstaclesSet.insert(to_string(obstacles[i][0]) + ',' + to_string(obstacles[i][1]));
        }
        
        int direction = 0, x = 0, y = 0, nextX = 0, nextY = 0, ans = 0;
        string obstacle;
        int mX[4] = {0, 1, 0, -1};
        int mY[4] = {1, 0, -1, 0};
        
        for(int i=0; i<commands.size(); i++){
            //commands[i]가 -1이면 오른쪽으로 90도 회전
            if(commands[i] == -1){
                direction++;
            }
            //-2이면 왼쪽으로 90도 회전
            else if(commands[i] == -2){
                direction--;
            }
            else{
                for(int j=0; j<commands[i]; j++){
                    nextX = x + mX[direction];
                    nextY = y + mY[direction];
                    
                    //다음 칸이 장애물인지 확인하고 장애물이면 그 자리에서 멈춘다
                    obstacle = to_string(nextX) + ',' + to_string(nextY);
                    if(obstaclesSet.find(obstacle) != obstaclesSet.end()){
                        break;
                    }
                    
                    x = nextX;
                    y = nextY;
                    
                    //최대 거리를 지속적으로 갱신한다
                    ans = max(ans, x*x + y*y);
                }
            }
            //direction의 값에따라 mX, mY 배열에 접근하는 idx가 다르다
            //direction이 0이면 북쪽, 1이면 동쪽, 2면 남쪽, 3이면 서쪽을 바라본다
            //-1의 경우 3과 같은 방향을, 4의 경우 0과 같은 방향을 바라본다
            direction = (direction + 4) % 4;
        }
        
        return ans;
    }
};
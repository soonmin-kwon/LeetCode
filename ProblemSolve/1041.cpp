/***************************
 * Robot Bounded In Circle *
 ***************************/

class Solution {
public:
    bool isRobotBounded(string instructions) {        
        int len = instructions.size();
        int dir = 0;
        int curX = 0, curY = 0;
        int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for(int i=0; i<len; ++i){
            if(instructions[i] == 'G'){
                curX += move[dir][0];
                curY += move[dir][1];
            }
            else if(instructions[i] == 'L'){
                dir = (dir + 3) % 4;
            }
            else{
                dir = (dir + 1) % 4;
            }            
        }    
        
        //한번 루틴을 끝냈을 때 제자리거나 다른 방향을 보고 있으면
        //결국 같은 영역을 돌도록 되어 있음.
        return (curX == 0 && curY == 0) || dir > 0;
    }
};
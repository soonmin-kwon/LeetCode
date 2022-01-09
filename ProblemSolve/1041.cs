/***************************
 * Robot Bounded In Circle *
 ***************************/

public class Solution {
    public bool IsRobotBounded(string instructions) {
        int len = instructions.Length;
        int dir = 0;
        int curX = 0, curY = 0;
        int[,] move = new int[4,2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        //instructions를 한번만 수행해도 다음 위치에 따라 결정할 수 있음
        //한번 수행하고 제자리에 돌아오면 무조건 true
        //한번 수행했을 때 다른 방향을 보고 있으면 결국 제자리에 돌아오게 됨
        foreach(char instruction in instructions){
            if(instruction == 'G'){
                curX += move[dir,0];
                curY += move[dir,1];
            }
            else if(instruction == 'L'){
                dir = (dir + 3) % 4;
            }
            else{
                dir = (dir + 1) % 4;
            }
        }
        
        return (curX == 0 && curY == 0) || dir > 0;
    }
}
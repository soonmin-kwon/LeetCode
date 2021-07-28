/*******************
 * Climbing Stairs *
 *******************/

class Solution {
public:
    int climbStairs(int n) {
        //계단을 오르는 방법의 수를 저장할 배열, 초기화
        int stairs[46];
        memset(stairs, 0, sizeof(stairs));
        
        //기본값 설정.
        stairs[0] = 0;
        stairs[1] = 1;
        stairs[2] = 2;
        
        //3번째 계단으로 올라오는 방법의 수는
        //첫 번째 계단에서 올라오는 방법의 수 + 두번째 계단에서 올라오는 방법의 수
        //따라서 stairs[n] = stairs[n-2] + stairs[n-1]
        for(int i=3; i<=n; i++){
            stairs[i] = stairs[i-2] + stairs[i-1];
        }
        
        return stairs[n];
    }
};
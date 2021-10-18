/***************
 * Ugly Number *
 ***************/

class Solution {
public:
    bool isUgly(int n) {
        //positive하지 않은 경우
        if(n <= 0){
            return false;
        }
        
        //2로 나눌 수 있을때까지 나눈다
        while(n % 2 == 0){
            n /= 2;
        }
        
        //3으로 나눌 수 있을때까지 나눈다
        while(n % 3 == 0){
            n /= 3;
        }
        
        //5로 나눌 수 있을때까지 나눈다
        while(n % 5 == 0){
            n /= 5;
        }
        
        //처음 주어진 n이 1이어도 true이다
        //현재 n이 1이면 위에 while문을 모두 돌고 온 것이므로 2,3,5로만 이뤄진 경우이다
        return n == 1 ? true : false;
    }
};
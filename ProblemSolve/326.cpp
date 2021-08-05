/******************
 * Power of Three *
 ******************/

class Solution {
public:
    bool isPowerOfThree(int n) {
        //1은 0승
        if(n == 1){
            return true;
        }
            
        if(n < 3){
            return false;
        }
        
        //3의 거듭제곱수인지 체크
        while(n != 1){
            if(n % 3 != 0){
                return false;
            }
            n /= 3;            
        }
        
        return true;
    }
};
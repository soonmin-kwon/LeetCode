/****************
 * Power of Two *
 ****************/

class Solution {
public:
    bool isPowerOfTwo(int n) {        
        if(n <= 0){
            return false;
        }
        
        int count = 0;
                        
        //1인 비트의 개수를 센다.        
        //1개면 2의 제곱수.
        while(n){
            n &= (n-1);
            count++;
        }
        
        //2의 제곱수는 비트가 1인 값이 한개인 수.
        //제곱수 - 1과 &연산을 하면 0이 나와야 제곱수.
        return ((n&(n-1)) == 0);
    }
};
/*********************
 * Number Complement *
 *********************/

class Solution {
public:
    int findComplement(int num) {
        //비교할 mask를 구한다
        //num의 비트값이 1이면 0으로, 0이면 1로 바꿔야 하므로 
        //num의 이진수 값과 같은 자리수를 가지고 모두 1인 마스크 값이 필요하다
        //num이 2^n <= num < 2^(n+1)이라 가정하면, num의 이진수 값의 자리수는 n+1이다
        //mask는 n+1의 자리수를 가지면서 모두 1이어야 하므로 mask = 2^(n+1) - 1이다.
        
        int idx = log2(num);
        //num이 INT_MAX인 경우 int의 범위를 넘는다
        int mask = (long)pow(2, idx + 1) - 1;
        
        return (mask ^ num);
    }
};
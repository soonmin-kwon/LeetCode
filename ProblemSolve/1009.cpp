/*********************************
 * Complement of Base 10 Integer *
 *********************************/

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0){
            return 1;
        }
        
        unsigned int mask = ~0;
        
        //n이 차지하고 있는 비트 수 만큼 left shift
        //ex) n = 5 = 101(2)
        //left shift한 후 ~를 하면 n이 차지하고 있는 비트 수 만큼만 1로 채워진 수가 됨.
        //후에 ^연산을 하면 1은 0으로 0은 1로 바뀜
        while((mask & n) > 0){
            mask <<= 1;
        }
        
        return ~mask ^ n;
    }
};
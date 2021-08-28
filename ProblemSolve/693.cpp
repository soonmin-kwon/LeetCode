/***************************************
 * Binary Number with Alternating Bits *
 ***************************************/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        //n의 2^0 비트 값 확인
        bool first = n & 1;
        bool second;
        
        while(n){
            //n 값을 오른쪽으로 한 칸 shift
            n >>= 1;
            
            //한 칸씩 계속 shift 하기 때문에 2^0 비트 값만 계속 확인하면 된다
            second = n & 1;
            
            //first와 second가 같으면 ...00...이거나, ...11...이다
            if(first == second){
                return false;
            }
            
            //first 갱신
            first = second;
        }
        
        return true;
    }
};
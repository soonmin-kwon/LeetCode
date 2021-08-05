/********************
 * Number of 1 Bits *
 ********************/

class Solution {
public:    
    int hammingWeight(uint32_t n) {
        int cnt=0;
        
        //끝자리 1인지 체크
        while(n > 0){
            if((n & 1) > 0){
                cnt++;
            }
            
            //오른쪽으로 쉬프트
            n = n >> 1;
        }
        
        return cnt;
    }
};
/****************
 * Reverse Bits *
 ****************/

class Solution {
public:        
    uint32_t reverseBits(uint32_t n){
        uint32_t ans = 0;
        int power = 31;
        
        //2^0 비트부터 체크해서 2^31 , 2^30 ... 으로 보낸다.
        while(n != 0){
            ans += (n & 1) << power;
            n = n >> 1;
            power--;
        }
        
        return ans;
    }
};
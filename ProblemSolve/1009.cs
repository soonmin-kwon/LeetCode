/*********************************
 * Complement of Base 10 Integer *
 *********************************/

public class Solution {
    public int BitwiseComplement(int n) {
        /*
        mask(~0) = 111...111
        ~5 = 111...010
        
        앞에 1로 채워진 비트를 없애면 됨
        mask를 3칸 left shift하면 111...000
        mask에 ~연산을 하면 000...111
        그 상태로 ^ 연산을 하면 뒤에 3자리만 남게 됨
        */
        
        if(n == 0){
            return 1;
        }
        
        var mask = ~0;
        
        //주어진 n에 맞춰 left shift
        while((mask & n) > 0){
            mask <<= 1;
        }
        
        //원하는 비트만 남김
        return ~mask ^ n;
    }
}
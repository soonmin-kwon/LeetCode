/*********************
 * Number Complement *
 *********************/

public class Solution {
    public int FindComplement(int num) {
        var mask = ~0;
        
        /*
        ex)
        mask = 111...1111111
        num = 8 = 1000
        after While => mask         = 111...11110000
                       num          = 000...00001000
                       ~mask        = 000...00001111
                       ~mask ^ num  = 000...00000111
        */
        
        while((mask & num) > 0){
            mask = mask << 1;
        }
        
        return ~mask ^ num;
    }
}
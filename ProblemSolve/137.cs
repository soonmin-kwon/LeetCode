/********************
 * Single Number II *
 ********************/

public class Solution {
    public int SingleNumber(int[] nums) {
        uint mask = 1;
        uint ans = 0;
        
        int count = 0;
        int len = nums.Length;
        
        for(int i=0; i<32; ++i){
            count = 0;
            
            for(int j=0; j<len; ++j){
                if((nums[j] & mask) >= 1){
                    count += 1;
                }
            }
            
            if((count % 3) != 0){
                ans += mask;
            }
            
            mask <<= 1;
        }
        
        return (int)ans;
    }
}
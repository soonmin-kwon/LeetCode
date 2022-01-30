/****************
 * Rotate Array *
 ****************/

public class Solution {
    public void Rotate(int[] nums, int k) {
        int len = nums.Length;
        
        if(len == 1){
            return;
        }
        
        k %= len;
        
        if(k == 0){
            return;
        }
        
        Array.Reverse(nums);
        
        Array.Reverse(nums, 0, k);
        Array.Reverse(nums, k, len-k);
        
        return;
    }
}
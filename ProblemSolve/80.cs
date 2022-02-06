/******************************************
 * Remove Duplicates from Sorted Array II *
 ******************************************/

public class Solution {
    public int RemoveDuplicates(int[] nums) {
        int idx = 0;
        
        foreach(var num in nums){
            if(idx < 2 || num > nums[idx-2]){
                nums[idx] = num;
                idx++;
            }
        }
        
        return idx;
    }
}
/*****************************
 * Find the Duplicate Number *
 *****************************/

public class Solution {
    public int FindDuplicate(int[] nums) {
        for(int i=0; i<nums.Length; ++i){
            if(nums[Math.Abs(nums[i])] < 0){
                return Math.Abs(nums[i]);
            }
            
            nums[Math.Abs(nums[i])] *= -1;
        }
        
        return -1;
    }
}
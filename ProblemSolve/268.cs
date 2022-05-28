/******************
 * Missing Number *
 ******************/

public class Solution {
    public int MissingNumber(int[] nums) {
        bool isContainZero = false;
        
        for(int i=0; i<nums.Length; ++i){
            if(nums[i] == 0){
                isContainZero = true;
            }
            else{
                int originalVal = Math.Abs(nums[i]);
                if(originalVal == nums.Length + 1){
                    isContainZero = true;
                    continue;
                }
                
                nums[originalVal - 1] *= -1;
                if(nums[originalVal - 1] == 0){
                    nums[originalVal - 1] = -nums.Length - 1;
                }
            }
        }
        
        if(!isContainZero){
            return 0;
        }
        
        for(int i=0; i<nums.Length; ++i){
            if(nums[i] >= 0){
                return i + 1;
            }
        }
        
        return 0;
    }
}
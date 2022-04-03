/********************
 * Next Permutation *
 ********************/

public class Solution {
    public void Swap(ref int a, ref int b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    public void NextPermutation(int[] nums) {        
        int permutationStartIdx = 0;
        
        for(int i=0; i<nums.Length-1; ++i){
            if(nums[i] < nums[i+1]){
                permutationStartIdx = Math.Max(permutationStartIdx, i);
            }
        }
        
        int swapTargetIdx = 0;
        
        for(int i=permutationStartIdx+1; i<nums.Length; ++i){
            if(nums[permutationStartIdx] < nums[i]){
                swapTargetIdx = Math.Max(swapTargetIdx, i);
            }
        }
        
        if(permutationStartIdx == swapTargetIdx){
            Array.Reverse(nums);
            return;
        }
        
        Swap(ref nums[permutationStartIdx], ref nums[swapTargetIdx]);
        Array.Reverse(nums, permutationStartIdx + 1, nums.Length - permutationStartIdx - 1);
        
        return;
    }
}
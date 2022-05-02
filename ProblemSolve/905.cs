/************************
 * Sort Array By Parity *
 ************************/

public class Solution {
    public void Swap(ref int a, ref int b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    public int[] SortArrayByParity(int[] nums) {
        int leftIdx = 0;
        int rightIdx = nums.Length - 1;
        
        while(leftIdx < rightIdx){
            if(nums[leftIdx] % 2 != 0){
                Swap(ref nums[leftIdx], ref nums[rightIdx]);
                rightIdx--;
            }
            else{
                leftIdx++;
            }
        }
        
        return nums;
    }
}
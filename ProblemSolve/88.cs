/**********************
 * Merge Sorted Array *
 **********************/

public class Solution {
    public void Merge(int[] nums1, int m, int[] nums2, int n) {
        int idx = m-- + n-- - 1;
        
        while(n >=0 && m >= 0){
            nums1[idx] = Math.Max(nums1[m], nums2[n]);
            
            if(nums1[m] >= nums2[n]){
                m--;
            }
            else{
                n--;
            }
            
            idx--;
        }
        
        while(n >= 0){
            nums1[idx--] = nums2[n--];
        }
    }
}
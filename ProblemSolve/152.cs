/****************************
 * Maximum Product Subarray *
 ****************************/

public class Solution {
    public void Swap(ref int a, ref int b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    //음수가 나오면 가장 작은 수가 가장 큰 수가 될 수 있음
    //가장 작은 수, 가장 큰 수를 동시에 저장하면서 진행
    public int MaxProduct(int[] nums) {
        int tempMaximum = nums[0];
        int tempMinimum = nums[0];
        
        int ans = nums[0];
        
        for(int i=1; i<nums.Length; ++i){
            if(nums[i] < 0){
                Swap(ref tempMaximum, ref tempMinimum);
            }
            
            tempMaximum = Math.Max(nums[i], tempMaximum * nums[i]);
            tempMinimum = Math.Min(nums[i], tempMinimum * nums[i]);
            
            ans = Math.Max(ans, tempMaximum);
        }
        
        return ans;
    }
}
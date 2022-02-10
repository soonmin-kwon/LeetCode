/********************************
 * Subarray Sums Divisible by K *
 ********************************/

public class Solution {
    public int SubarraySum(int[] nums, int k) {
        int sum = 0;
        int ans = 0;
        Dictionary<int, int> hash = new Dictionary<int, int>(){{0, 1}};
        
        foreach(int num in nums){
            sum += num;
            
            if(hash.ContainsKey(sum - k)){
                ans += hash[sum - k];
            }
            
            if(hash.ContainsKey(sum)){
                hash[sum]++;
            }
            else{
                hash[sum] = 1;
            }            
        }
        
        return ans;
    }
}
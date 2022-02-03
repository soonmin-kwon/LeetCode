/***********
 * 4Sum II *
 ***********/

public class Solution {
    public int FourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        Dictionary<int, int> hash = new Dictionary<int, int>();
        int ans = 0;
        
        foreach(int num1 in nums1){
            foreach(int num2 in nums2){
                if(hash.ContainsKey(num1 + num2)){
                    hash[num1 + num2]++;
                }
                else{
                    hash.Add(num1 + num2, 1);
                }
            }
        }
        
        // num1 + num2 + num3 + num4 = 0
        // num1 + num2 = -(num3 + num4)
        foreach(int num3 in nums3){
            foreach(int num4 in nums4){
                if(hash.ContainsKey(-num3-num4)){
                    ans += hash[-(num3 + num4)];
                }                
            }
        }
        
        return ans;
    }
}
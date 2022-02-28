/******************
 * Summary Ranges *
 ******************/

public class Solution {
    public IList<string> SummaryRanges(int[] nums) {
        List<string> ans = new List<string>();
        
        if(nums.Length == 0){
            return ans;
        }
        
        int start = nums[0];
        int prev = nums[0];
        
        for(int i=1; i<nums.Length; ++i){
            if(nums[i] - 1 != prev){
                if(start == prev){
                    ans.Add(String.Format("{0}", start));
                }
                else{
                    ans.Add(String.Format("{0}->{1}", start, prev));
                }
                start = nums[i];
            }
            
            prev = nums[i];
        }
        
        if(start == prev){
            ans.Add(String.Format("{0}", start));
        }
        else{
            ans.Add(String.Format("{0}->{1}", start, prev));
        }
        
        return ans;
    }
}
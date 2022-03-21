/********************
 * Partition Labels *
 ********************/

public class Solution {
    public IList<int> PartitionLabels(string s) {
        int[] last = new int[26];
        
        for(int i=0; i<s.Length; ++i){
            last[(int)(s[i] - 'a')] = i;
        }
        
        int idx = 0, anchor = 0;
        List<int> ans = new List<int>();
        
        for(int i=0; i<s.Length; ++i){
            idx = Math.Max(idx, last[(int)(s[i] - 'a')]);
            
            if(i == idx){
                ans.Add(i - anchor + 1);
                anchor = i+1;
            }
        }
        
        return ans;
    }
}
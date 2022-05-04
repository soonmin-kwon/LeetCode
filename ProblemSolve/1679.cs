/*****************************
 * Max Number of K-Sum Pairs *
 *****************************/

public class Solution {
    public int MaxOperations(int[] nums, int k) {
        Dictionary<int, int> hash = new Dictionary<int, int>();
        int ans = 0;
        
        foreach(int num in nums){
            if(hash.ContainsKey(num)){
                hash[num]++;
            }
            else{
                hash.Add(num, 1);
            }
        }
        
        foreach(var item in hash){
            int num = item.Key;
            int count = item.Value;
            
            if(k - num == num){
                ans += count / 2;
            }
            else if(hash.ContainsKey(k - num)){
                int min = Math.Min(count, hash[k-num]);
                ans += min;
                
                hash[num] -= min;
                hash[k - num] -= min;
            }
        }
        
        return ans;
    }
}
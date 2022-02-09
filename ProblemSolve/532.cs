/****************************
 * K-diff Pairs in an Array *
 ****************************/

public class Solution {
    public int FindPairs(int[] nums, int k) {
        Dictionary<int, int> hash = new Dictionary<int, int>();
        HashSet<int> ansSet = new HashSet<int>();
        
        foreach(int num in nums){
            if(hash.ContainsKey(num - k)){
                ansSet.Add(num);
            }
            
            if(hash.ContainsKey(num + k)){
                ansSet.Add(num + k);
            }
            
            hash[num] = 1;
        }
        
        return ansSet.Count;
    }
}
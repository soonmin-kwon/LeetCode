/***************************
 * Top K Frequent Elements *
 ***************************/

public class Solution {
    public int[] TopKFrequent(int[] nums, int k) {
        int len = nums.Length;
        
        if(k == len){
            return nums;
        }
        
        Dictionary<int, int> hash = new Dictionary<int,int>();
        for(int i=0; i<len; ++i){
            if(!hash.TryGetValue(nums[i], out int val)){
                hash[nums[i]] = 1;
            }
            else{
                hash[nums[i]]++;
            }
        }
        
        PriorityQueue<int,int> pq = new PriorityQueue<int,int>();
        
        foreach(var element in hash){
            pq.Enqueue(element.Key, -element.Value);
        }
        
        int[] ans = new int[k];
        
        for(int i=0; i<k; ++i){
            ans[i] = pq.Dequeue();
        }
        
        return ans;
    }
}
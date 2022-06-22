/***********************************
 * Kth Largest Element in an Array *
 ***********************************/

public class Solution {
    public int FindKthLargest(int[] nums, int k) {
        int ans = 0;
        PriorityQueue<bool, int> pq = new PriorityQueue<bool, int>();
        
        foreach(int num in nums){
            pq.Enqueue(true, -num);
        }
        
        for(int i=0; i<k; ++i){
            pq.TryDequeue(out bool _temp, out int element);
            ans = -element;
        }
        
        return ans;
    }
}
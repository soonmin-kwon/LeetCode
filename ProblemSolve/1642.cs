/***********************************
 * Furthest Building You Can Reach *
 ***********************************/

public class Solution {
    public int FurthestBuilding(int[] heights, int bricks, int ladders) {
        PriorityQueue<bool, int> pq = new PriorityQueue<bool, int>();
        int idx = 0;
        
        for(idx = 0; idx < heights.Length - 1; ++idx){
            if(heights[idx+1] > heights[idx]){
                int gap = heights[idx+1] - heights[idx];
                
                bricks -= gap;
                pq.Enqueue(true, -gap);
                
                if(bricks < 0){
                    pq.TryDequeue(out bool _b, out int brick);
                    bricks -= brick;
                    ladders--;
                }
                
                if(ladders < 0){
                    return idx;
                }
            }
        }
        
        return idx;
    }
}
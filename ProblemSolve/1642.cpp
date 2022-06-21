/***********************************
 * Furthest Building You Can Reach *
 ***********************************/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int idx = 0;      
        for(idx=0; idx<heights.size() - 1; ++idx){
            if(heights[idx+1] > heights[idx]){
                int gap = heights[idx+1] - heights[idx];
                
                bricks -= gap;
                pq.push(gap);
                
                if(bricks < 0){
                    bricks += pq.top();
                    pq.pop();
                    ladders--;
                }
                
                if(ladders < 0){
                    return idx;
                }
            }
        }
        
        return idx;
    }
};
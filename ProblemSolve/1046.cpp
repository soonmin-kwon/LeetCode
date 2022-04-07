/*********************
 * Last Stone Weight *
 *********************/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        for(int stone : stones){
            pq.push(stone);
        }
        
        while(pq.size() > 1){
            int stoneY = pq.top();
            pq.pop();
            int stoneX = pq.top();
            pq.pop();
            
            if(stoneX < stoneY){
                pq.push(stoneY - stoneX);
            }
        }
        
        return pq.size() == 1 ? pq.top() : 0;
    }
};
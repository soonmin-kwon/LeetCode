/*********************
 * Last Stone Weight *
 *********************/

public class Solution {
    public int LastStoneWeight(int[] stones) {
        PriorityQueue<int, int> pq = new PriorityQueue<int, int>();
        
        foreach(int stone in stones){
            pq.Enqueue(stone, -stone);
        }
        
        while(pq.Count > 1){
            int stoneY = pq.Dequeue();
            int stoneX = pq.Dequeue();
            
            Console.WriteLine(stoneY);
            Console.WriteLine(stoneX);
            
            if(stoneX < stoneY){
                pq.Enqueue(stoneY - stoneX, stoneX - stoneY);
            }
        }
        
        return pq.Count == 1 ? pq.Dequeue() : 0;
    }
}
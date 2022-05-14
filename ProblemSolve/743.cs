/**********************
 * Network Delay Time *
 **********************/

public class Solution {
    public struct DelayAndTarget{
        public int delay;
        public int target;
        
        public DelayAndTarget(int delay, int target){
            this.delay = delay;
            this.target = target;
        }
    }
    
    public int NetworkDelayTime(int[][] times, int n, int k) {
        Dictionary<int, List<DelayAndTarget>> graph = new Dictionary<int, List<DelayAndTarget>>();
        PriorityQueue<DelayAndTarget, int> pq = new PriorityQueue<DelayAndTarget, int>();
        List<int> dist = new List<int>(n + 1);
        
        for(int i=0; i<=n; ++i){
            dist.Add(Int32.MaxValue);
        }
        
        foreach(var info in times){
            if(!graph.ContainsKey(info[0])){
                graph.Add(info[0], new List<DelayAndTarget>());
                graph[info[0]].Add(new DelayAndTarget(info[2], info[1]));
            }
            else{
                graph[info[0]].Add(new DelayAndTarget(info[2], info[1]));
            }
        }
        
        dist[0] = -1;
        dist[k] = 0;
        
        pq.Enqueue(new DelayAndTarget(dist[k], k), dist[k]);
        
        DelayAndTarget nodeInfo;
        int distance, vertex;
        int weight, next, sum;
        
        while(pq.Count > 0){
            nodeInfo = pq.Dequeue();
            
            distance = nodeInfo.delay;
            vertex = nodeInfo.target;
            
            if(vertex < 0 || vertex >= dist.Count){
                Console.WriteLine(vertex);
                continue;
            }
            
            if(dist[vertex] != distance){
                Console.WriteLine(vertex);
                continue;
            }
            
            if(!graph.ContainsKey(vertex)){
                continue;
            }
            
            foreach(var info in graph[vertex]){
                weight = info.delay;
                next = info.target;
                
                sum = distance + weight;
                
                if(sum < dist[next]){
                    dist[next] = sum;
                    
                    if(next < 0 || next >= dist.Count){
                        Console.WriteLine(next);
                        continue;
                    }
                    pq.Enqueue(new DelayAndTarget(dist[next], next), dist[next]);
                }
            }
        }
        
        int ans = 0;
        
        foreach(var d in dist){
            ans = Math.Max(ans, d);
        }
        
        return (ans == Int32.MaxValue) ? -1 : ans;
    }
}
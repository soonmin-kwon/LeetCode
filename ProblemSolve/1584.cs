/**********************************
 * Min Cost to Connect All Points *
 **********************************/

public class Solution {
    List<int> parent = new List<int>();
    
    public int findParent(int x){
        if(parent[x] == x){
            return x;
        }
        
        return parent[x] = findParent(parent[x]);
    }
    
    public bool hasSameParent(int x, int y){
        x = findParent(x);
        y = findParent(y);
        
        if(x == y){
            return true;
        }
        else{
            return false;
        }
    }
    
    public void unionNode(int x, int y){
        x = findParent(x);
        y = findParent(y);
        
        if(x != y){
            parent[y] = x;
        }
    }
    
    public struct DistAndPoint{
        public int dist;
        public int x;
        public int y;
        
        public DistAndPoint(int dist, int x, int y){
            this.dist = dist;
            this.x = x;
            this.y = y;
        }
    }
    
    public int MinCostConnectPoints(int[][] points) {
        int len = points.Length;
        int dist = 0;
        int answer = 0;
        
        List<DistAndPoint> graph = new List<DistAndPoint>();
        
        for(int i = 0; i<len; i++){
            parent.Add(i);
        }
        
        for(int i=0; i<len; i++){
            for(int j = i+1; j<len; j++){
                dist = Math.Abs(points[i][0] - points[j][0]) + Math.Abs(points[i][1] - points[j][1]);
                graph.Add(new DistAndPoint(dist, i, j));
            }
        }
        
        graph.Sort((e1, e2) => e1.dist.CompareTo(e2.dist));
        len = graph.Count;
        
        for(int i=0; i<len; i++){
            if(!hasSameParent(graph[i].x, graph[i].y)){
                unionNode(graph[i].x, graph[i].y);
                answer += graph[i].dist;
            }
        }

        return answer;
    }
}
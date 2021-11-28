/***********************************
 * All Paths From Source to Target *
 ***********************************/

public class Solution {
    //DFS 방식으로 경로 탐색
    public void GetPaths(int[][] graph, ref IList<IList<int>> ans, List<int> path, int node, int size){
        if(node == size){
            ans.Add(path.ToList());
            return;
        }
        
        //Backtracking
        foreach(int next in graph[node]){
            path.Add(next);
            GetPaths(graph, ref ans, path, next, size);
            path.RemoveAt(path.Count - 1);
        }
        
        return;
    }
    
    public IList<IList<int>> AllPathsSourceTarget(int[][] graph) {
        IList<IList<int>> ans = new List<IList<int>>();
        List<int> path = new List<int>() {0};
        
        GetPaths(graph, ref ans, path, 0, graph.Length - 1);
        return ans;
    }
}
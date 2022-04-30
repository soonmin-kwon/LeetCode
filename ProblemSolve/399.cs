/*********************
 * Evaluate Division *
 *********************/

public class Solution {
    public struct NodeInfo{
        public string path;
        public double weight;
        
        public NodeInfo(string path, double weight){
            this.path = path;
            this.weight = weight;
        }
    }
    
    Dictionary<string, List<NodeInfo>> graph = new Dictionary<string, List<NodeInfo>>();
    Dictionary<string, bool> visitied = new Dictionary<string, bool>();
    double queryAns;
    
    public bool DFS(string startNode, string endNode, double currEval){
        List<NodeInfo> info = null;
        
        if(startNode == endNode && graph.TryGetValue(startNode, out List<NodeInfo> t)){
            info = t;
            queryAns = currEval;
            return true;
        }
        
        bool temp = false;
        visitied[startNode] = true;
        
        for(int i=0; i<(graph.ContainsKey(startNode) ? graph[startNode].Count : 0); ++i){
            if(!visitied[graph[startNode][i].path]){
                temp = DFS(graph[startNode][i].path, endNode, currEval * graph[startNode][i].weight);
                if(temp){
                    break;
                }
            }
        }
        
        visitied[startNode] = false;
        
        return temp;
    }
    
    public double[] CalcEquation(IList<IList<string>> equations, double[] values, IList<IList<string>> queries) {
        int len1 = equations.Count;
        int len2 = queries.Count;
        
        List<double> ans = new List<double>(len2);
        
        for(int i=0; i<len1; ++i){
            if(!graph.ContainsKey(equations[i][0])){
                graph.Add(equations[i][0], new List<NodeInfo>(){new NodeInfo(equations[i][1], values[i])});
            }
            else{
                graph[equations[i][0]].Add(new NodeInfo(equations[i][1], values[i]));
            }
            
            if(!graph.ContainsKey(equations[i][1])){
                graph.Add(equations[i][1], new List<NodeInfo>(){new NodeInfo(equations[i][0], 1/values[i])});
            }
            else{
                graph[equations[i][1]].Add(new NodeInfo(equations[i][0], 1/values[i]));
            }
            
            if(!visitied.ContainsKey(equations[i][0])){
                visitied.Add(equations[i][0], false);
            }
            
            if(!visitied.ContainsKey(equations[i][1])){
                visitied.Add(equations[i][1], false);
            }
        }
        
        for(int i=0; i<len2; ++i){
            queryAns = 1;
            bool hasPath = DFS(queries[i][0], queries[i][1], 1.0);
            ans.Add(hasPath ? queryAns : -1);
        }
        
        return ans.ToArray();
    }
}
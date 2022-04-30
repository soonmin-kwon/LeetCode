/*********************
 * Evaluate Division *
 *********************/

class Solution {
private:    
    unordered_map<string, vector<pair<string, double>>> graph;
    unordered_map<string, bool> visited;
    double queryAns;
public:
    bool dfs(string startNode, string endNode, double curEvaluate){
        if(startNode == endNode && graph.find(startNode)!=graph.end()) {
            queryAns = curEvaluate;
            return true;
        }
        
        bool tempAns = false;
        visited[startNode] = true;
        
        for(int i = 0; i < graph[startNode].size(); i++){
            if(!visited[graph[startNode][i].first]){
                tempAns = dfs(graph[startNode][i].first, endNode, curEvaluate*graph[startNode][i].second);
                if(tempAns){
                    break;
                }
            }
        }
        
        visited[startNode] = false;
        
        return tempAns;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int len1 = equations.size(), len2 = queries.size();
        vector<double> ans(len2);
        
        for(int i = 0; i < len1 ; i++){
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1/values[i]});
            visited[equations[i][0]] = false;
            visited[equations[i][1]] = false;

        }
        
        for(int i = 0; i < len2 ; i++){
            queryAns = 1;
            bool pathFound = dfs(queries[i][0], queries[i][1], 1.0);
            if(pathFound)
                ans[i] = queryAns;
            else
                ans[i] = -1;
        }
        
        return ans;
        
    }
};
/***********************************
 * All Paths From Source to Target *
 ***********************************/

class Solution {
public:
    //DFS 방식으로 경로를 탐색
    void getPaths(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int> path, int node, int& size){
        //마지막 노드 도달 시에 path를 정답에 추가
        if(node == size){
            ans.push_back(path);
            return;
        }
        
        int len = graph[node].size();
        
        //Backtracking
        for(int i=0; i<len; i++){
            path.push_back(graph[node][i]);
            getPaths(graph, ans, path, graph[node][i], size);
            path.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int size = graph.size()-1;
        getPaths(graph, ans, {0}, 0, size);
        
        return ans;
    }
};
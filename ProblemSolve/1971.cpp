/*******************************
 * Find if Path Exits in Graph *
 *******************************/

class Solution {
public:
    //end 점까지 갈 수 있는 path가 있는지 확인한다
    //DFS 방식으로 확인
    bool checkHasPath(vector<vector<int>>& graph, vector<bool>& visitied, int cur, int end) {
        //end 점까지 도착했으면 true 리턴
        if(cur == end){
            return true;
        }
        
        //무한 재귀 방지
        if(visitied[cur]){
            return false;
        }        
        visitied[cur] = true;
        
        //cur 점에서 갈 수 있는 모든 점으로 이동한다
        //도착할 수 있으면 true 리턴
        for(auto ver : graph[cur]){
            if(checkHasPath(graph, visitied, ver, end)){
                return true;
            }
        }
        
        //위에 loop을 다 돌았는데 못 도착하면 false
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> graph(n);
        vector<bool> visitied(n);
        
        //양방향 그래프이므로 두 방향 모두 graph에 추가해준다
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        return checkHasPath(graph, visitied, start, end);
    }
};
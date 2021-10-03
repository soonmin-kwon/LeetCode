/*******************
 * Course Schedule *
 *******************/

class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& visitied, int node){
        //방문한 노드로 체크
        visitied[node] = 1;
        
        for(int i=0; i<graph[node].size(); i++){
            //시작 node에서 사이클이 생기는 경우 false
            if(visitied[graph[node][i]] == 1){
                return false;
            }
            
            if(visitied[graph[node][i]] == 0){
                //사이클이 생긴 경우 false
                if(!dfs(graph, visitied, graph[node][i])){
                    return false;
                }
            }
        }
        
        //이미 확인한 노드로 체크
        visitied[node] = 2;
        
        return true;
    }
    
    //사이클이 생기는 경우 모든 course를 수료하지 못한다
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        
        vector<int> visitied(numCourses);
        
        //그래프 생성
        for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for(int i=0; i<numCourses; i++){
            //현재 노드에서 사이클이 만들어지는지 확인
            if(visitied[i] == 0){
                if(!dfs(graph, visitied, i)){
                    return false;
                }
            }
        }
        
        return true;
    }
};
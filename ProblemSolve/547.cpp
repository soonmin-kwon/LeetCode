/***********************
 * Number of Provinces *
 ***********************/

class Solution {
public:
    //각 idx별 부모 저장
    vector<int> parent;
    
    //부모의 값을 찾는다
    int findParent(int x){
        if(parent[x] == x){
            return x;
        }
        else{
            return parent[x] = findParent(parent[x]);
        }
    }

    //같은 부모를 가지고 있는지
    bool hasSameParent(int x, int y){
        x = findParent(x);
        y = findParent(y);
        
        if(x==y){
            return true;
        }
        else{
            return false;
        }
    }
    
    //두 마을의 부모를 최신화
    void unionPv(int x, int y){
        x = findParent(x);
        y = findParent(y);
        
        if(x != y){
            parent[y] = x;
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int len = isConnected.size();
        
        parent.resize(len);
        //부모 값 자기 자신으로 초기화
        for(int i=0; i<len; i++){
            parent[i] = i;            
        }
        
        vector<pair<int,int>> graph;
        
        for(int i=0; i<len; i++){
            for(int j=i + 1; j<len; j++){                
                //그래프 정보 저장
                if(isConnected[i][j]){
                    graph.push_back(make_pair(i, j));
                }                
            }
        }
        
        len = graph.size();
        
        //모든 마을을 돌면서 가능한 마을끼리 합친다
        for(int i=0; i<len; i++){
            if(!hasSameParent(graph[i].first, graph[i].second)){
                unionPv(graph[i].first, graph[i].second);                                
            }
        }        
        
        //위의 과정을 거쳐도 모든 연결된 마을의 정보가 갱신되는 것이 아니기 때문에
        //한번 더 반복해서 parent 배열을 갱신한다
        for(int i=0; i<len; i++){
            if(!hasSameParent(graph[i].first, graph[i].second)){
                unionPv(graph[i].first, graph[i].second);
            }
        }
        
        unordered_set<int> count;
        
        len = isConnected.size();
        
        for(int i=0; i<len; i++){      
            count.insert(parent[i]);
        }
        
        return count.size();
    }
};
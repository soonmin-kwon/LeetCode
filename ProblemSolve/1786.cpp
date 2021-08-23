/*******************************************************
 * Number of Restricted Paths From First to Last Node *
 *******************************************************/

class Solution {
public:
    int dfs(unordered_map<int, vector<pair<int,int>>>& graph, int start, vector<int>& v, vector<int>& dist){
        //시작점에 도착했는지 확인
        if(start == 1){
            return 1;
        }
        
        //이미 방문했는지
        if(v[start] != -1){
            return v[start];
        }
        
        int weight, val, sum = 0;
        int len = graph[start].size();
        
        for(int i=0; i<len; i++){
            weight = dist[start];
            val = dist[graph[start][i].first];
            
            //graph[start][i].first는 도착점, start는 시작점이고
            //끝점에서부터 시작하기 때문에 한칸 이전으로 가는 거와 동일
            //따라서 distanceToLastNode(도착점) > distanceToLastNode(시작점)이 되어야만
            //1부터 시작했다고 가정했을 때 점점 distanceToLastNode()값이 작아진다
            if(val > weight){
                sum = (sum % 1000000007 + dfs(graph, graph[start][i].first, v, dist) % 1000000007) % 1000000007;
            }
        }
        
        return v[start] = sum % 1000000007;        
    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        //시작점, 도착점, 거리
        unordered_map<int, vector<pair<int, int>>> graph;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n + 1, INT_MAX);
        vector<int> v(n+1, -1);
        int len = edges.size();
        
        //edges[i][0] -> edges[i][1]까지 거리가 edges[i][2]
        for(int i=0; i<len; i++){
            graph[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
            graph[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
        }
        
        dist[n] = 0;
        pq.push(make_pair(dist[n], n));
        pair<int, int> node;
        int distance, ver;
        int weight, next, sum;
        
        //Dijkstra Algorithm
        //끝 지점부터 시작해서 distanceToLastNode(x) 계산
        while(!pq.empty()){
            node = pq.top();
            pq.pop();
            
            distance = node.first;
            ver = node.second;
            
            if(dist[ver] != distance){
                continue;
            }
            
            len = graph[ver].size();
            for(int i=0; i<len; i++){
                weight = graph[ver][i].second;
                next = graph[ver][i].first;
                
                sum = distance + weight;
                
                if(sum < dist[next]){
                    dist[next] = sum;
                    pq.push(make_pair(dist[next], next));
                }
            }
        }
        
        return dfs(graph, n, v, dist);
    }
};
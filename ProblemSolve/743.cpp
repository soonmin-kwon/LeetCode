/**********************
 * Network Delay Time *
 **********************/

class Solution {
public:
    //Dijkstra Algorithm with Heap
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //현재 노드, 거리, 도착 노드
        unordered_map<int, vector<pair<int,int>>> graph;
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        vector<int> dist(n + 1, INT_MAX);
                
        for(auto info : times){
            graph[info[0]].push_back(make_pair(info[2], info[1]));
        }
        dist[0] = -1;
        dist[k] = 0;
        
        pq.push(make_pair(dist[k], k));
        
        pair<int, int> node;
        int distance, ver;
        int weight, next, sum;
        
        while(!pq.empty()){
            node = pq.top();
            pq.pop();
            
            distance = node.first;
            ver = node.second;
            
            if(dist[ver] != distance){
                continue;
            }
            
            for(auto x : graph[ver]){
                weight = x.first;
                next = x.second;
                
                sum = distance + weight;
                
                if(sum < dist[next]){
                    dist[next] = sum;
                    pq.push(make_pair(dist[next], next));
                }
            }
        }
        
        int ans = 0;
        //ans가 INT_MAX면 그 노드에 도달할 수 없다는 뜻
        for(auto d : dist){
            ans = max(ans, d);
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};

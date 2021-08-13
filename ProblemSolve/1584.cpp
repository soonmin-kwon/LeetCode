/**********************************
 * Min Cost to Connect All Points *
 **********************************/

class Solution {
public:
    //각 노드의 부모를 저장
    vector<int> parent;
    
    //부모를 찾는다
    int findParent(int x){
        if(parent[x] == x){
            return x;
        }
        else{
            return parent[x] = findParent(parent[x]);
        }
    }
    
    //두 노드가 같은 부모를 가지는지, 연결되어 있는지 확인
    bool hasSameParent(int x, int y){
        x = findParent(x);
        y = findParent(y);
        
        if(x == y){
            return true;
        }
        else{
            return false;
        }
    }
    
    //두 노드를 연결한다
    void unionNode(int x, int y){
        x = findParent(x);
        y = findParent(y);
        
        if(x != y){
            parent[y] = x;
        }
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int len = points.size();
        int dist = 0;
        int answer = 0;
        vector<pair<int, pair<int, int>>> v;
        
        //초기 부모는 자기 자신
        for(int i = 0; i<len; i++){
            parent.push_back(i);
        }
        
        //각 점마다 다른 모든 점과의 거리를 재서 거리, 시작점, 도착점 저장
        for(int i=0; i<len; i++){
            for(int j = i+1; j<len; j++){
                dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                v.push_back(make_pair(dist, make_pair(i, j)));
            }
        }
        
        //거리가 낮은 순으로 정렬
        sort(v.begin(), v.end());
        len = v.size();
        
        //두 노드의 부모가 같은지 확인, 같지 않으면 연결, 같으면 스킵
        for(int i=0; i<len; i++){
            if(!hasSameParent(v[i].second.first, v[i].second.second)){
                unionNode(v[i].second.first, v[i].second.second);
                answer += v[i].first;
            }
        }

        return answer;
    }
};
/*********************************
 * Path with Maximum Probability *
 *********************************/

class Solution {
public:
    //Dijkstra Algorithm
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {                
        unordered_map<int, vector<pair<double, int>>> graph;
        priority_queue<pair<double, int>> pq;
        
        
        vector<double> prob(n , 0.0);           //probability 정보 저장
        vector<bool> visitied(n);               //중복 방지
        
        //그래프 정보 저장
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(make_pair(succProb[i], edges[i][1]));
            graph[edges[i][1]].push_back(make_pair(succProb[i], edges[i][0]));
        }
        
        //0.0으로 시작하면 곱 연산이 불가, 고로 1.0으로 시작
        prob[start] = 1.0;
        
        pq.push(make_pair(prob[start], start));
        
        pair<double, int> node;
        double probability, probNext, probCal;
        int ver, next;
        
        //Dijkstra Algorithm
        while(!pq.empty()){
            node = pq.top();
            pq.pop();
            
            probability = node.first;
            ver = node.second;
            
            if(!visitied[ver]){
                visitied[ver] = true;
                
                for(auto x : graph[ver]){
                    probNext = x.first;
                    next = x.second;
                
                    probCal = probNext * probability;
                    
                    //더 큰 확률을 가지게끔 진행
                    if(probCal > prob[next]){
                        prob[next] = probCal;
                        pq.push(make_pair(prob[next], next));
                    }
                }
            }
        }

        return prob[end];
    }
};
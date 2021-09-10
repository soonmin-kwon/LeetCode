/**************************************************
 * Number of Operations to Make Network Connected *
 **************************************************/

class Solution {
public:
    //주어진 연결 상태를 유지할 수 있는 최소 cable 수
    int cnt = 0;
    
    void dfs(int n, unordered_map<int, vector<int>>& network, vector<bool>& visitied){
        //중복 탐색 방지
        visitied[n] = true;
        
        for(auto computer : network[n]){
            //연결할 수 있으면 cnt 값을 1씩 늘린다.
            if(!visitied[computer]){
                cnt++;
                dfs(computer, network, visitied);
            }
        }
        
        return;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cables = connections.size();
        //성립이 안 되는 경우, 연결 해야하는 computer의 개수가 cable의 수 보다 많은 경우
        if(n - 1 > cables){
            return -1;
        }
        
        vector<bool> visitied(n);        
        unordered_map<int, vector<int>> network;        //graph 저장
        
        int group = 0;      //연결해야할 그룹의 수
        
        for(auto computer : connections){
            network[computer[0]].push_back(computer[1]);
            network[computer[1]].push_back(computer[0]);
        }
        
        //연결해야할 그룹의 수를 구한다.
        for(int i=0; i<n; i++){
            if(!visitied[i]){
                group++;
                dfs(i, network, visitied);
            }            
        }
        
        //사용 가능한 cable의 개수
        int remain = cables - cnt;
        
        //각 그룹을 남은 cable로 연결할 수 있는지 확인
        if(group - 1 <= remain){
            return group - 1;
        }
        
        return -1;
    }
};
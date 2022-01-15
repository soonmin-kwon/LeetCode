/****************
 * Jump Game IV *
 ****************/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int len = arr.size() - 1;
        int ans = 0;
        
        queue<int> q;                               //현재 idx저장 queue
        vector<bool> visitied(len+1);               //중복 탐색 못하도록 방지
        unordered_map<int,vector<int>> hash;        //idx값 저장
        
        for(int i=0; i<=len; ++i){
            hash[arr[i]].push_back(i);
        }
        
        q.push(0);
        visitied[0] = true;
        
        //BFS
        while(!q.empty()){
            for(int i=q.size(); i>0; --i){
                int idx = q.front();
                q.pop();
                
                if(idx == len){
                    return ans;
                }
                
                vector<int>& canJump = hash[arr[idx]];
                //갈 수 있는 곳을 추가해준다
                canJump.push_back(idx-1);
                canJump.push_back(idx+1);
                
                for(auto next : canJump){
                    if(0 <= next && next <= len && !visitied[next]){
                        q.push(next);
                        visitied[next] = true;
                    }
                }
                //이미 갈 수 있는 idx로 다 갔으니까 재참조 안하게 없앰.
                canJump.clear();
            }
            
            ans++;
        }

        return 0;
    }
};
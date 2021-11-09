/***************************
 * Lexicographical Numbers *
 ***************************/

class Solution {
public:
    void dfs(vector<int>& ans, int cur, int n){
        if(cur > n){
            return;
        }
        
        ans.push_back(cur);
        dfs(ans, cur * 10, n);
        
        //1, 10, 100 ...이 먼저 들어간 상태에서
        //9 + 1, 99 + 1...  등이 들어가면 중복됨.
        if((cur + 1) % 10 != 0){
            dfs(ans, cur + 1, n);
        }
        
        return;
    }
    
    //DFS Ver.
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        dfs(ans, 1, n);
        
        return ans;
    }
    
    //Iterative Ver.
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int cur = 1;
        
        for(int i=1; i<=n; i++){
            ans.push_back(cur);
            
            //사전적으로 앞쪽에 위치하면서 찾을 수 있는 가장 큰 수 찾기
            if(cur * 10 <= n){
                cur *= 10;
            }
            //사전적으로 앞쪽에 있는 숫자들이 순서대로 들어가도록 한다
            else if(cur % 10 != 9 && cur + 1 <= n){
                cur++;
            }
            else{
                //가장 작은수로 넘어가기
                while((cur / 10) % 10 == 9){
                    cur /= 10;
                }
                cur = cur/10 + 1;
            }
        }
        
        return ans;
    }
};
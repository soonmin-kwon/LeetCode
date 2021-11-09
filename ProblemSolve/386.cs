/***************************
 * Lexicographical Numbers *
 ***************************/

public class Solution {
    public void dfs(List<int> ans, int cur, int n){
        if(cur > n){
            return;
        }
        
        ans.Add(cur);        
        dfs(ans, 10*cur, n);
        
        //10, 100, 1000...은 이미 정답에 추가 된 상태에서
        //cur = 9, 99, 999인 경우에는 정답에 추가하면 안된다.
        if((cur + 1) % 10 != 0){
            dfs(ans, cur + 1, n);
        }
        
        return;
    }
    
    //DFS Ver.
    public IList<int> LexicalOrder(int n) {
        List<int> ans = new List<int>();
        dfs(ans, 1, n);
        return ans;
    }
    
    //Iterative Ver.
    public IList<int> LexicalOrder(int n) {
        List<int> ans = new List<int>();
        int cur = 1;
        
        for(int i=1; i<=n; i++){
            ans.Add(cur);
            //맨 앞자리 숫자를 유지하면서 큰 수를 찾는다
            if(cur * 10 <= n){
                cur *= 10;
            }
            //앞자리 수를 유지하면서 1씩 늘려서 사전적으로 제일 작은 수를 찾는다
            else if(cur % 10 != 9 && cur + 1 <=n){
                cur++;
            }
            //맨 앞자리가 같은 숫자를 만들 수 있는 최대로 만들면 다음 앞자리로 넘어감
            //ex) n = 21, cur = 19 ==> cur = 2로 넘김
            else{
                while((cur / 10) % 10 == 9){
                    cur /= 10;
                }
                cur = cur / 10 + 1;
            }
        }
        
        return ans;
    }
}
/*****************
 * Jump Game III *
 *****************/

class Solution {
public:
    //중복해서 탐색하면 무한재귀에 빠질 수 있음
    //애초에 탐색했던 곳을 다시 탐색할 이유가 없음. 그 곳에서 출발하면 도착지는 같기 때문
    bool dfs(vector<int>& arr, vector<bool>& visitied, int start){
        if(start < 0 || start >= arr.size() || visitied[start]){
            return false;
        }
        
        visitied[start] = true;
        if(arr[start] == 0){
            return true;
        }
        
        return dfs(arr, visitied, start - arr[start]) || dfs(arr, visitied, start + arr[start]);
    }
    
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visitied(arr.size(), false);
        return dfs(arr, visitied, start);
    }
};
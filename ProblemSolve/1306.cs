/*****************
 * Jump Game III *
 *****************/

public class Solution {
    //중복해서 탐색하면 무한재귀에 빠질 수 있음
    //애초에 탐색했던 곳을 다시 탐색할 이유가 없음. 그 곳에서 출발하면 도착지는 같기 때문
    public bool Dfs(int[] arr, ref bool[] visitied, int start){
        if(start < 0 || start >= arr.Length || visitied[start] == true){
            return false;
        }
        
        visitied[start] = true;
        if(arr[start] == 0){
            return true;
        }
        
        return Dfs(arr, ref visitied, start - arr[start]) || Dfs(arr, ref visitied, start + arr[start]);
    }
    public bool CanReach(int[] arr, int start) {
        bool[] visitied = new bool[arr.Length];
        return Dfs(arr, ref visitied, start);
    }
}
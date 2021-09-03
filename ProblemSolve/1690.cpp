/******************
 * Stone Game VII *
 ******************/

class Solution {
public:
    int game(vector<vector<int>>& dp, int start, int end, int sum, vector<int>& stones){
        //범위를 벗어나면 리턴
        if(start >= end){
            return 0;
        }
        
        //이미 갱신된 값이면 리턴
        if(dp[start][end] != 0){
            return dp[start][end];
        }
        
        //sum은 이미 전체 배열을 합한 값
        //앨리스와 밥 모두 최적의 선택을 해야한다
        //고로 앨리스 차례던 밥 차례던 최대값으로만 선택하면 optimal한 선택이 된다
        dp[start][end] = max(sum - stones[start] - game(dp, start + 1, end, sum - stones[start], stones),
                             sum - stones[end] - game(dp, start, end - 1, sum - stones[end], stones));
        
        return dp[start][end];
    }
    
    int stoneGameVII(vector<int>& stones) {
        int len = stones.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        
        int sum = 0;
        
        //prefix Sum
        for(auto x : stones){
            sum += x;
        }
        
        return game(dp, 0, len-1, sum, stones);        
    }
};
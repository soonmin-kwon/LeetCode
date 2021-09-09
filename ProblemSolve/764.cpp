/*********************
 * Largest Plus Sign *
 *********************/

//참고 : https://leetcode.com/problems/largest-plus-sign/solution/

class Solution {
public:    
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        unordered_set<int> hash;
        int ans = 0;
        int mem;
        
        //좌표값을 변환시켜 고유한 값으로 만든다, 1차원 hash로 값을 찾을 수 있다.
        for(auto x : mines){
            //ex) n = 6 -> 4,2 = 26, 5,2 = 32
            hash.insert(x[0] * n + x[1]);
        }
        
        //r,c점을 기준으로 가능한 + 모양의 최대 길이를 저장
        vector<vector<int>> dp(n, vector<int>(n));
        
        /*
        ex) n = 5, mines = [[4, 2]]
        1 1 1 1 1
        1 1 1 1 1
        1 1 1 1 1
        1 1 1 1 1
        1 1 0 1 1
        */
        //r, c를 기준으로 해서 왼쪽으로 가능한 최대거리, 오른쪽으로 가능한 최대거리를 계산
        for(int r=0; r<n; r++){
            mem = 0;
            
            //왼쪽으로 가능한 최대거리 계산
            //row = 4일 경우 dp[0] = [1, 2, 0, 1, 2]
            for(int c=0; c<n; c++){
                mem = hash.find(r * n + c) != hash.end() ? 0 : mem + 1;
                dp[r][c] = mem;
            }
            
            mem = 0;
            
            //오른쪽으로 가능한 최대거리 계산
            //row = 4일 경우 dp[0] = [min(1, 2), min(2, 1), min(0, 0), min(1, 2), min(2, 1)]
            for(int c=n-1; c>=0; c--){
                mem = hash.find(r * n + c) != hash.end() ? 0 : mem + 1;
                dp[r][c] = min(mem, dp[r][c]);
            }
        }
        
        //r, c를 기준으로 해서 위로 가능한 최대거리, 아래로 가능한 최대거리를 계산
        for(int c=0; c<n; c++){
            mem = 0;
            
            //위로 가능한 최대거리 계산
            //col = 2일 경우 dp[?][2] = [1, 2, 3, 4, 0]
            for(int r=0; r<n; r++){
                mem = hash.find(r * n + c) != hash.end() ? 0 : mem + 1;
                dp[r][c] = min(mem, dp[r][c]);
            }
            
            mem = 0;
            
            //아래로 가능한 최대거리 계산
            //col = 2일 경우 dp[?][2] = [4, 3, 2, 1, 0]            
            //row = 4, col = 2일 경우 dp[4][2] = min(0, 0, 1)
            for(int r=n-1; r>=0; r--){                
                mem = hash.find(r * n + c) != hash.end() ? 0 : mem + 1;
                dp[r][c] = min(mem, dp[r][c]);
                //모든 경우의 수를 확인했기 때문에 정답 계산
                ans = max(dp[r][c], ans);
            }
        }
        
        return ans;
    }
};
/*******************************
 * Best Team With No Conflicts *
 *******************************/

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v;
        int len = scores.size();
        vector<int> dp(len + 1, 0);
        
        //나이 순으로 정렬하기 위해 나이를 first로 넣는다
        for(int i=0; i<len; i++){
            v.push_back(make_pair(ages[i], scores[i]));
        }
        
        int ans = INT_MIN;
        //나이 순으로 정렬
        sort(v.begin(), v.end());
        
        for(int i=0; i<len; i++){
            dp[i] = v[i].second;
            
            for(int j=0; j<i; j++){
                //i번째 idx가 j보다 무조건 나이가 많기 때문에
                //v[i].second가 더 작다면 팀으로 넣지 않는다
                //이전에 구해놓은 최대값에 더해야 최대값이 되기때문에 모든 j를 돌면서 구한다
                if(v[i].second >= v[j].second){
                    dp[i] = max(dp[i], dp[j] + v[i].second);
                }
            }

            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};
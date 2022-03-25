/***********************
 * Two City Scheduling *
 ***********************/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(),
            [](vector<int>& a, vector<int>& b){
                return abs(a[0] - a[1]) > abs(b[0] - b[1]);
            });
        
        int aCount = 0, bCount = 0;
        int maxCount = costs.size() / 2;
        int ans = 0;
        
        for(int i=0; i<costs.size(); ++i){
            if(costs[i][0] > costs[i][1]){
                if(bCount == maxCount){
                    ans+= costs[i][0];
                    continue;
                }
                bCount++;
                ans += costs[i][1];
            }
            else{
                if(aCount == maxCount){
                    ans+= costs[i][1];
                    continue;
                }
                aCount++;
                ans += costs[i][0];
            }
        }
        
        return ans;
    }
};
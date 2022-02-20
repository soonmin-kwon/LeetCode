/****************************
 * Remove Covered Intervals *
 ****************************/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = 0, left = -1, right = -1;
        sort(intervals.begin(), intervals.end());
        
        for(auto& interval : intervals){
            if(interval[0] > left && interval[1] > right){
                left = interval[0];
                ans++;
            }
            
            right = max(interval[1], right);
        }
        
        return ans;
    }
};
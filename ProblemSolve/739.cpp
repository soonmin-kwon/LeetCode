/**********************
 * Daily Temperatures *
 **********************/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        int warmest = temperatures.back();
        int len = temperatures.size();
        
        for(int i=len-2; i>=0; i--){
            int todayTemp = temperatures[i];
            
            if(todayTemp >= warmest){
                warmest = todayTemp;
                continue;
            }
            
            int warmerDay = 1;
            while(temperatures[i + warmerDay] <= todayTemp){
                warmerDay += ans[i + warmerDay];
            }
            
            ans[i] = warmerDay;
        }
        
        return ans;
    }
};
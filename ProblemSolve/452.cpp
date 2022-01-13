/**********************************************
 * Minimum Number of Arrows to Burst Balloons *
 **********************************************/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int len = points.size();
        
        if(len == 1){
            return 1;
        }
        
        sort(points.begin(), points.end(), 
             [](vector<int>& a, vector<int>& b){
                return a[1] < b[1];
        });
        
        int arrowPoint = points[0][1];
        int ans = 1;
        
        for(int i=1; i<len; i++){
            if(arrowPoint < points[i][0]){
                ans++;
                arrowPoint = points[i][1];
            }
        }
                
        return ans;        
    }
};
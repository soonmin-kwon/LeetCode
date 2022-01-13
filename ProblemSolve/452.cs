/**********************************************
 * Minimum Number of Arrows to Burst Balloons *
 **********************************************/

public class Solution {
    public int FindMinArrowShots(int[][] points) {
        int len = points.Length;
        
        if(len == 1){
            return 1;
        }
        
        Array.Sort(points, (a, b) => a[1].CompareTo(b[1]));
        
        int ans = 1;
        int arrowPoint = points[0][1];
        
        for(int i=1; i<len; ++i){
            if(arrowPoint < points[i][0]){
                ++ans;
                arrowPoint = points[i][1];
            }            
        }
        
        return ans;
    }
}

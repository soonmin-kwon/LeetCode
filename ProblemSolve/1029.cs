/***********************
 * Two City Scheduling *
 ***********************/

public class Solution {
    private static void Sort(int[][]data){
        Comparer<int> comparer = Comparer<int>.Default;
        Array.Sort<int[]>(data, 
                          (x, y) =>
                          {
                              int a = Math.Abs(x[0] - x[1]);
                              int b = Math.Abs(y[0] - y[1]);
                              
                              return b.CompareTo(a);
                          });
    }
    
    public int TwoCitySchedCost(int[][] costs) {
        Sort(costs);
        
        int aCount = 0, bCount = 0;
        int maxCount = costs.Length / 2;
        int ans = 0;
        
        for(int i=0; i<costs.Length; ++i){
            if(costs[i][0] > costs[i][1]){
                if(bCount == maxCount){
                    ans += costs[i][0];
                    continue;
                }
                bCount++;
                ans += costs[i][1];
            }
            else{
                if(aCount == maxCount){
                    ans += costs[i][1];
                    continue;
                }
                
                aCount++;
                ans += costs[i][0];
            }
        }
        
        return ans;
    }
}
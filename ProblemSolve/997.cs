/***********************
 * Find the Town Judge *
 ***********************/

public class Solution {
    public int FindJudge(int n, int[][] trust) {
        int[] counts = new int[n+1];
        
        foreach(var temp in trust){
            counts[temp[0]]--;
            counts[temp[1]]++;
        }
        
        for(int i=1; i<=n; ++i){
            if(counts[i] == n-1){
                return i;
            }
        }
        
        return -1;
    }
}
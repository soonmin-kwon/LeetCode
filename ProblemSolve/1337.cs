/**********************************
 * The K Weakest Rows in a Matrix *
 **********************************/

public class Solution {
    public int[] KWeakestRows(int[][] mat, int k) {
        SortedDictionary<int,List<int>> weakRows = new SortedDictionary<int,List<int>>();
        int[] ans = new int[k];
        
        for(int i=0; i<mat.Length; ++i){
            int soldierCount = 0;
            for(int j=0; j<mat[i].Length; ++j){
                soldierCount += mat[i][j];    
            }
            
            if(weakRows.ContainsKey(soldierCount)){
                weakRows[soldierCount].Add(i);
            }
            else{
                weakRows.Add(soldierCount, new List<int>(){i});
            }
        }
        
        int idx=0;
        foreach(int soldierCount in weakRows.Keys){
            foreach(int row in weakRows[soldierCount]){
                ans[idx] = row;
                ++idx;
                
                if(idx==k){
                    break;
                }
            }
            
            if(idx==k){
                break;
            }
        }
        
        return ans;
    }
}
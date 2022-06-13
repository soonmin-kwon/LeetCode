/************
 * Triangle *
 ************/

public class Solution {
    public int MinimumTotal(IList<IList<int>> triangle) {
        int row = 0;
        int col = 0;
        
        for(row = triangle.Count - 2; row >= 0; --row){
            for(col = 0; col < triangle[row].Count; ++col){
                triangle[row][col] += Math.Min(triangle[row+1][col], triangle[row+1][col+1]);
            }
        }
        
        return triangle[0][0];
    }
}
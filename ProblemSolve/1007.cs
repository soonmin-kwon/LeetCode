/******************************************
 * Minimum Domino Rotations For Equal Row *
 ******************************************/

public class Solution {
    public int MinDominoRotations(int[] tops, int[] bottoms) {
        int[] topCounts = new int[7];
        int[] bottomCounts = new int[7];
        int[] sameCounts = new int[7];
        
        int ans = -1;
        
        for(int i=0; i<tops.Length; ++i){
            if(tops[i] == bottoms[i]){
                sameCounts[tops[i]]++;
            }
            
            topCounts[tops[i]]++;
            bottomCounts[bottoms[i]]++;
        }
        
        for(int i=1; i<7; ++i){
            if(topCounts[i] + bottomCounts[i] - sameCounts[i] == tops.Length){
                ans = Math.Max(tops.Length - Math.Max(topCounts[i], bottomCounts[i]), ans);
            }
        }
        
        return ans;
    }
}
/*****************************
 * Container With Most Water *
 *****************************/

public class Solution {
    public int MaxArea(int[] height) {
        int leftIdx = 0, rightIdx = height.Length - 1;
        int leftHeight, rightHeight, smallerHeight;
        
        int ans = 0;
        
        while(leftIdx < rightIdx){
            leftHeight = height[leftIdx];
            rightHeight = height[rightIdx];
            
            smallerHeight = Math.Min(leftHeight, rightHeight);
            ans = Math.Max(ans, smallerHeight * (rightIdx - leftIdx));
            
            if(leftHeight < rightHeight){
                leftIdx++;
            }
            else{
                rightIdx--;
            }
        }
        
        return ans;
    }
}
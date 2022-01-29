/**********************************
 * Largest Rectangle in Histogram *
 **********************************/

//참고 : https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/28902/5ms-O(n)-Java-solution-explained-(beats-96)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int len = heights.size();
        
        vector<int> firstLowerHeightIdxFromLeft(len);
        vector<int> firstLowerHeightIdxFromRight(len);
        firstLowerHeightIdxFromRight[len-1] = len;
        firstLowerHeightIdxFromLeft[0] = -1;
        
        for(int i=1; i<len; ++i){
            int j = i-1;
            
            while(j >= 0 && heights[j] >= heights[i]){
                j = firstLowerHeightIdxFromLeft[j];
            }
            firstLowerHeightIdxFromLeft[i] = j;            
        }

        for(int i=len-2; i>=0; --i){
            int j = i+1;
            
            while(j < len && heights[j] >= heights[i]){
                j = firstLowerHeightIdxFromRight[j];
            }
            firstLowerHeightIdxFromRight[i] = j;
        }
        
        for(int i=0; i<len; ++i){
            ans = max(ans, heights[i]  * (firstLowerHeightIdxFromRight[i] - firstLowerHeightIdxFromLeft[i] - 1));
        }
        
        return ans;
    }
};
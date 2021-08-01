/***********************
 * Trapping Rain Water *
 ***********************/

class Solution {
public:
    //백준 빗물(14719) 문제와 똑같은 문제
    int trap(vector<int>& height) {
        int len = height.size();
        
        if(len == 0){
            return 0;
        }
        
        int ans = 0;
        vector<int> leftMax(len);
        vector<int> rightMax(len);
        
        leftMax[0] = height[0];
        rightMax[len-1] = height[len-1];
        
        //현 지점을 기준으로 왼쪽으로 제일 높은 벽, 오른쪽으로 제일 높은 벽을 저장
        for(int i=1; i<len; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
            rightMax[len - 1 - i] = max(rightMax[len - i], height[len -1 - i]);            
        }
        
        //각 지점을 돌면서 더 낮은 벽을 찾고 현 지점의 벽만큼 빼주면 물이 차는 양
        for(int i=0; i<len; i++){
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        
        return ans;
    }
};
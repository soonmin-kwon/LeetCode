/*****************************
 * Container With Most Water *
 *****************************/

class Solution {
public:
    // O(n)
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() -1;
        int leftWall, rightWall, h;
        int ans = 0;
        
        //더 작은 벽을 바꿔서 더 큰 벽끼리 값을 계산한다.
        //거리를 1 줄이면서 벽 값을 늘린다.
        while( left < right ){
            leftWall = height[left];
            rightWall = height[right];
            
            h = min(leftWall, rightWall);
            ans = max(ans, h * (right - left));
            
            if(leftWall < rightWall){
                left++;
            }
            else{
                right--;
            }
        }
        
        return ans;        
    }
    
    // O(n^2) - 시간초과
    int maxArea(vector<int>& height) {
        int len = height.size();
        int left = 0, right = len, ans = 0;
        int leftWall, rightWall, h;
        
        //모든 경우의 수 탐색
        for(int i=0; i<len; i++){
            for(int j = len - 1; j>=i; j--){
                leftWall = height[i];
                rightWall = height[j];
                
                h = min(leftWall, rightWall);
                ans = max(ans, h * (j - i));
            }
        }
        
        return ans;
    }
};
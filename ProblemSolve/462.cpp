/********************************************
 * Minimum Moves to Equal Array Elements II *
 ********************************************/

class Solution {
public:
    //제일 작은수를 기준으로 하면 제일 큰 수의 경우 너무 많은 move가 생긴다
    //제일 큰수를 기준으로 해하면 제일 작은 수의 경우 너무 많은 move가 생긴다
    //제일 큰수, 제일 작은 수 모두 최소의 움직임을 가지려면
    //중간 값을 골라서 중간값을 기준으로 맞춰주면 된다.
    int minMoves2(vector<int>& nums) {
        
        //중간 값을 찾기 위한 sort
        sort(nums.begin(), nums.end());
        
        int lenNums = nums.size();
        //중간 값 찾기
        int middleNum = nums[lenNums / 2];  
        int ans = 0;
        
        //중간 값과의 차이만큼 움직인다
        for(auto num : nums){
            ans += abs(num - middleNum);
        }
        
        return ans;
    }
};
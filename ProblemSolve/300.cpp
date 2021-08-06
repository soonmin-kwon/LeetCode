/**********************************
 * Longest Increasing Subsequence *
 **********************************/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> lis;
        lis.push_back(nums[0]);
        
        //binary search + DP
        for(int i = 1; i < len; i++){
            //주어진 배열에 있는 값이 현재 부분수열에서 몇번째로 작은지 체크
            auto it = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
            
            //제일 큰 값이면 넣어준다.
            if(it >= lis.size()){
                lis.push_back(nums[i]);
            }
            //제일 크지 않으면 그 값을 더 작게 바꿔준다. 
            //더 작은 값을 가지면 계속해서 값을 비교할 때 유리하다
            else{
                lis[it] = nums[i];
            }
        }
               
        return lis.size();
    }
};
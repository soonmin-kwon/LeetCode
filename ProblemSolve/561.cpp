/*********************
 * Array Partition I *
 *********************/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        //최대한 작은 값들끼리 비교해서 작은 값을 뽑아내야 더 큰 값을 살릴 수 있다
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        int len = nums.size();
        
        //2개씩 pair를 만들기 때문에 비교가 되는 두 값 중에서 더 작은 값들만 뽑는다
        for(int i=0; i<len; i +=2){
            ans += nums[i];
        }
        
        return ans;
    }
};
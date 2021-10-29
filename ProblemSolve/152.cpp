/****************************
 * Maximum Product Subarray *
 ****************************/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        
        int maximum = nums[0];
        int minimum = nums[0];        
        int ans = nums[0];
        
        //곱의 최대값을 찾는 것이기 때문에 모든 수를 곱하는 것이 유리하다
        //maximum에는 제일 큰 연속된 곱의 값을 저장하고
        //minimum에는 제일 작은 연속된 곱의 값을 저장한다
        //nums[i]가 음수인 경우 maximum과 minimum을 바꿔서 진행하면
        //가장 작은수가 minimum으로, 가장 큰 수가 maximum으로 바뀌고 제대로 진행될 수 있다.
        //가장 작은 수가 음수인 상태에서 음수가 한번 더 나온다면 그 수는 가장 큰 수가 될 것이다
        for(int i=1; i<nums.size(); i++){            
            //
            if(nums[i] < 0){
                int temp = maximum;
                maximum = minimum;
                minimum = temp;                
            }
            
            maximum = max(nums[i], maximum *nums[i]);
            minimum = min(nums[i], minimum * nums[i]);
            ans = max(ans, maximum);
        }
        
        return ans;
    }
};
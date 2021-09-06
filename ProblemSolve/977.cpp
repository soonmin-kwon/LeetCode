/*****************************
 * Squares of a Sorted Array *
 *****************************/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len);
        
        int left = 0;
        int right = len-1;
        int idx = len - 1;
        
        //주어진 nums 배열은 이미 non-decresing으로 정렬되어있다        
        //nums 배열이 음수를 포함하고 있는 경우와, 음수를 포함하고 있지 않은 경우로 나눌 수 있다
        
        //음수를 포함하지 않은 경우
        //단순하게 마지막 값부터 처음 값까지 차례대로 제곱해서 정답 배열에 넣어주면 된다.
        
        //음수를 포함하고 있는 경우
        //가장 작은 값인 nums[0]은 음수 중에서는 가장 큰 절대값을 가진다.
        //제곱의 크기는 절대값이 좌우하기 때문에 two pointer를 이용해 절대값을 비교해 나가며 정답 배열에 추가하면 된다.
        
        //two pointer는 음수를 포함하고 있지 않은 경우에도 적용이 가능하다.        
        while(left <= right){
            if(abs(nums[left]) > abs(nums[right])){
                ans[idx--] = nums[left] * nums[left++];                
            }
            else{
                ans[idx--] = nums[right] * nums[right--];
            }
        }
        
        return ans;
    }
};
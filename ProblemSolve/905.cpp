/************************
 * Sort Array By Parity *
 ************************/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        //배열 양 끝을 확인하면서 홀수를 뒤로 몰아넣는다
        while(left < right){
            //홀수를 뒤쪽으로 몰아넣는다
            if(nums[left] % 2 != 0){
                swap(nums[left], nums[right]);
                right--;
            }
            //짝수인 경우 그대로 둔다
            else{
                left++;
            }
        }
        
        return nums;
    }
};
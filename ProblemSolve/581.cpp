/*****************************************
 * Shortest Unsorted Continuous Subarray *
 *****************************************/

//참고 : https://leetcode.com/problems/shortest-unsorted-continuous-subarray/solution/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        
        bool flag = false;
        int len = nums.size();
        
        //제대로 정렬되어 있지 않은 부분에서 제일 작은 값을 찾는다
        for(int i=1; i<len; i++){
            if(nums[i] < nums[i-1]){
                flag = true;
            }
            
            if(flag){
                minimum = min(minimum, nums[i]);
            }
        }
        
        flag = false;
        
        //제대로 정렬되어 있지 않은 부분에서 제일 큰 값을 찾는다
        for(int i=len - 2; i>= 0; i--){
            if(nums[i] > nums[i+1]){
                flag = true;
            }
            
            if(flag){
                maximum = max(maximum, nums[i]);
            }
        }
        
        int left, right;
        //위에서 찾은 minimum, maximum값은 제대로 정렬되어 있지 않은 subarray를 정렬했을때 
        //제일 처음에 나오는 값과 제일 마지막에 나오는 값이 된다
        //ex) nums = [2,6,4,8,10,9,15] -> minimum = 4, maximum = 10
        
        //제대로 오름차순으로 정렬되도록 해야하기 때문에
        //minimum보다 큰 값이 나오면 그 idx부터 정렬을 시작해야 한다
        for(left = 0; left<len; left++){
            if(minimum < nums[left]){
                break;
            }
        }
        
        //maximum보다 작은 값이 나오면 그 idx까지 정렬을 해야한다
        for(right = len-1; right>=0; right--){
            if(maximum > nums[right]){
                break;
            }
        }
        
        //right - left < 0이면 이미 정렬되어있는 상태        
        return right - left < 0 ? 0 : right - left + 1;
    }
};
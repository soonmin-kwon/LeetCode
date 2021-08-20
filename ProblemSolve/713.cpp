/********************************
 * Subarray Product Less Than K *
 ********************************/

class Solution {
public:    
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<= 1){
            return 0;
        }
        
        int len = nums.size();
        int left = 0;        
        int product = 1;
        int ans = 0;
        
        //한칸씩 뒤로 이동하면서 조건을 만족하는 subarray의 개수를 찾는다
        //i - left만큼의 길이를 가지는 window를 생성해 window 길이에 따라 subarray의 개수가 생성된다
        //i - left길이 만큼의 값을 곱해도 k보다 작다면 
        //i - left의 길이에 속하는 벡터로 만들 수 있는 모든 subarray는 조건을 만족할 수 밖에 없다
        //ex) nums = [10, 5, 2, 6], k = 100
        //i = 0, left = 0 -> product = 10, ans = 1 -> {10}, 중복되지 않는 모든 subarray = {10}
        //i = 1, left = 0 -> product = 50, ans = 3 -> {10, 5}, 중복되지 않는 모든 subarray = {5}, {10, 5}
        //i = 2, left = 1 -> product = 10, ans = 5 -> {5, 2}, 중복되지 않는 모든 subarray = {2}, {5, 2}
        //i = 3, left = 1 -> product = 60, ans = 8 -> {5, 2, 6}, 중복되지 않는 모든 subarray = {6}, {2, 6}, {5, 2, 6}
        for(int i = 0; i<len; i++){
            product *= nums[i];
            while(product >= k){
                product /= nums[left];
                left++;
            }
            
            ans+= i - left + 1;
        }
        
        return ans;
    }
    
    /*
    시간초과
    모든 시작 idx에대해 만들 수 있는 모든 subarray를 체크해서 하나씩 답을 추가
    int ans = 0;
        
    void subarrayProduct(vector<int>& nums, int idx, int sum, int k){
        if(idx == nums.size()){
            return;
        }
        
        sum *= nums[idx];
        
        if(sum >= k){
            return;
        }
        
        ans++;
        subarrayProduct(nums, idx+1, sum, k);
    }
    
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0){
            return 0;
        }
        
        int len = nums.size();
        
        for(int i=0; i<len; i++){
            subarrayProduct(nums, i, 1, k);
        }
        
        return ans;
    }
    */
};
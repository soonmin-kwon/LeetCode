/*************************
 * Maximum Erasure Value *
 *************************/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int len = nums.size();
        int temp = 0;
        int ans = 0;
        
        //개수 세기, unique한 element인지 확인
        unordered_map<int,int> counts;
        
        while(right < len){
            counts[nums[right]]++;
            temp += nums[right];
            
            //포함 된 subarray가 unique하지 않은 경우
            //다시 unique하게 만들려고 window의 폭을 감소
            while(counts[nums[right]] > 1){
                counts[nums[left]]--;
                temp -= nums[left];
                left++;
            }
            
            //가장 큰 subarray의 sum 저장
            ans = max(ans, temp);
            right++;
        }
        
        return ans;
    }
};
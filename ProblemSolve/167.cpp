/**************************************
 * Two Sum II - Input array is sorted *
 **************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        
        int left = 0;
        int right = numbers.size() - 1;        
        
        //양끝에서 움직여서 값을 구한다
        //정렬 되어있기 때문에 타겟 값보다 작으면 left를 움직여 값을 키우고
        //타겟 값보다 크면 right를 움직여 값을 줄여나간다
        while(left <= right){
            if(numbers[left] + numbers[right] < target){
                left++;
            }
            else if(numbers[left] + numbers[right] > target){
                right--;
            }
            else{
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                break;
            }
        }
        
        return ans;
    }
};
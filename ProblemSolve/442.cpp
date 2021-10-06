/***********************************
 * Find All Duplicates in an Array *
 ***********************************/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        //nums의 element 값에 따른 idx값 저장
        int idx;
        
        //주어진 nums의 size는 n이고 nums[i]는 모두 1보다 크거나 같고 n보다 작거나 같다
        //nums[i]의 값들을 a라고 하면 a - 1값은 무조건 nums의 범위 안으로 들어온다
        //a값은 한번이거나 두번 불러지므로 nums[a-1]값에 *-1을 해서 한번들어있는지 두번들어있는지 확인한다
        for(int i=0; i<nums.size(); i++){
            //-1이 곱해져있는 경우에도 확인을 해야하기 때문에 절대값을 이용해 idx에 접근한다
            idx = abs(nums[i]) - 1;
        
            //-1을 곱해 유일한 값인지 아닌지 확인한다
            nums[idx] *= -1;
            
            //유일한 값이라면 음수이고 양수이면 유일한 값이 아니기 때문에 정답에 추가한다
            if(nums[idx] > 0){
                ans.push_back(idx + 1);
            }
        }
        
        return ans;
    }
};
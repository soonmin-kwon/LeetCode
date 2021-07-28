/******************
 * Remove Element *
 ******************/

class Solution {
public:    
    int removeElement(vector<int>& nums, int val) {
        int idx = 0, idx2 = nums.size() - 1;
        
        //양 끝에서 idx가 겹치기 전까지 확인
        //왼쪽으로 val이 아닌 값을 몰기 위해 idx로 val을 찾고 idx2로 val이 아닌 값을 찾는다.
        while(idx <= idx2){            
            //왼쪽이 val이고 오른쪽이 val이 아니면 
            //왼쪽 값을 idx2번째 값으로 바꾸고 idx 값들을 바꿔준다.
            //idx 값을 바꿔줘서 다시 체크하지 않도록 한다.
            if(nums[idx] == val && nums[idx2] != val){                
                nums[idx] = nums[idx2];
                idx++;
                idx2--;                
            }
            //왼쪽 값이 이미 val이 아니면 넘어간다.
            else if(nums[idx] != val){
                idx++;
            }
            //마찬가지로 오른쪽 값이 이미 val이면 넘어간다.
            else if(nums[idx2] == val){                
                idx2 --;
            }
        }
        
        return idx2 + 1;
    }
};
/***************
 * Sort Colors *
 ***************/

class Solution {
public:
    void sortColors(vector<int>& nums) {        
        int left = 0;
        int pivot = 0;
        int right = nums.size()-1;
        
        while(left <= right){            
            //0을 왼쪽으로 몬다
            if(nums[left] == 0){
                //pivot을 left가 0일때만 증가시켜서 세 포인터중에 제일 왼쪽에 존재하도록 한다
                swap(nums[left], nums[pivot]);
                left++;
                pivot++;
            }
            //2를 오른쪽으로 몬다
            else if(nums[left] == 2){
                swap(nums[left], nums[right]);
                right--;
            }            
            else{
                left++;                
            }
        }
        
        return;
    }
};
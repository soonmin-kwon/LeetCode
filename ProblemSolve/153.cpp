/****************************************
 * Find Minimum in Rotated Sorted Array *
 ****************************************/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        
        /*
        ex) 4 5 6 7 0 1 2 3
        low = 0, high = 7, mid = 3
        
        7 > 3 -> low = 4
        
        low = 4, high = 7, mid = 5
        0 < 3 -> high = 5
        
        low = 4, high = 5, mid = 4
        0 < 1 -> high = 4
        
        
        */ 
        while(low < high) { 
            mid = (low + high) / 2;
            
            //mid 기준 left에 작은 값 보유
            if(nums[mid] < nums[high]){
                high = mid;
            }
            //mid 기준 right에 작은 값 보유
            else{
                low = mid + 1;
            }
        }
        
        return nums[low];
    }
};
/****************
 * 3Sum Closest *
 ****************/

// 참고 : https://leetcode.com/problems/3sum-closest/discuss/7883/C%2B%2B-solution-O(n2)-using-sort

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size() - 1 ;
        sort(nums.begin(), nums.end());        
        int closest = nums[0] + nums[1] + nums[2];
        int second, third;
                
        for(int first = 0; first < len-1; first++){            
            second = first + 1;
            third = len;
            
            while(second < third){
                int currSum = nums[first] + nums[second] + nums[third];
                if(currSum == target){
                    return currSum;
                }
                
                if(abs(target - currSum) < abs(target - closest)){
                    closest = currSum;
                }
                
                if(currSum > target){
                    third--;
                }
                else {
                    second++;
                }
            }            
        }        
        
        return closest;        
    }
};
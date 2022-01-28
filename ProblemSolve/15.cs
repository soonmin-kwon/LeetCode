/********
 * 3Sum *
 ********/

public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        List<IList<int>> ans = new List<IList<int>>();
        if(nums == null || nums.Length < 3){
            return ans;
        }
        
        int len = nums.Length;
        Array.Sort(nums);
        
        int leftPointer;
        int rightPointer;
        
        for(int i=0; i<len-2; ++i){
            if(nums[i] > 0 || (i > 0 && nums[i] == nums[i-1])){
                continue;
            }
            
            leftPointer = i+1;
            rightPointer = len-1;
            
            while(leftPointer < rightPointer){
                int tempSum = nums[i] + nums[leftPointer] + nums[rightPointer];
                
                if(tempSum == 0){
                    ans.Add(new List<int>(){nums[i], nums[leftPointer], nums[rightPointer]});
                    leftPointer++;
                    rightPointer--;
                    
                    while(leftPointer < rightPointer && nums[leftPointer] == nums[leftPointer-1]){
                        leftPointer++;
                    }
                    
                    while(leftPointer < rightPointer && nums[rightPointer] == nums[rightPointer+1]){
                        rightPointer--;
                    }
                }
                else if(nums[i] + nums[leftPointer] + nums[rightPointer] < 0){
                    leftPointer++;
                }
                else{
                    rightPointer--;
                }
            }
        }
        
        return ans;
    }
}
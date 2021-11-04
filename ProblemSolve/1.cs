/***********
 * Two Sum *
 ***********/

public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        var hash = new Dictionary<int, int>();
        
        //hash의 key를 nums[i]로 설정하고 val을 index 값으로 하면
        //target - nums[i]값을 키로 갖고 있는지 찾았을 때
        //두 값을 찾고 index 값도 구할 수 있다
        for(int i=0; i<nums.Length; i++){                        
            if(hash.ContainsKey(target - nums[i])){
                return new int[]{hash[target - nums[i]], i};
            }
            else if(!hash.ContainsKey(nums[i])){
                hash.Add(nums[i], i);
            }
        }
        
        return new int[2];
    }
}
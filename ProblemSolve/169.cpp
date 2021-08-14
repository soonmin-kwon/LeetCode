/********************
 * Majority Element *
 ********************/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        
        unordered_map<int, int> map;
        
        //각 원소의 개수를 센다
        for(int i=0; i<len; i++){
            map[nums[i]] += 1;
            
            //어떤 원소의 개수가 조건을 만족하면 바로 리턴
            if(map[nums[i]] > (len / 2)){
                return nums[i];
            }
        }
        
        return 0;
    }
};
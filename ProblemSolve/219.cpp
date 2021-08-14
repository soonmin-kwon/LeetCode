/*************************
 * Contains Duplicate II *
 *************************/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        unordered_map<int, int> map;
        
        int distance = 0;
        
        for(int i = 0; i < len; i++) {
            //map에 존재하는 값인지 확인
            auto it = map.find(nums[i]);
            
            //존재하면
            if(it != map.end()){
                //존재하던 값과 지금 값의 거리를 측정
                distance = i - map[nums[i]];
                //조건에 만족하면 리턴
                if(distance <= k){
                    return true;
                }
            }
            
            //계속 값을 변경해도 k이하를 만족해야하기 때문에 상관 없다
            map[nums[i]] = i;
        }
        
        return false;
    }
};
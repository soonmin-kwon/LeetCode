/********************************
 * Binary Prefix Divisible By 5 *
 ********************************/

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int x = 0;
        vector<bool> ans; 
        
        //nums의 값을 차례대로 추가하면서 값을 확인한다
        //ex) nums = [1,0,1,1]
        //x = 1 => 1
        //x = 10 => 2
        //x = 101 => 5, 5 %= 5 = 0
        //x = 1 => 1
        for(int i=0; i<nums.size(); i++){
            //nums 값에 맞게 마지막 비트 값을 바꾼다
            x |= (nums[i]);
            //overflow 방지
            x %= 5;
            
            ans.push_back(!x);
            //왼쪽으로 shift해서 한칸을 늘린다
            x = x << 1;
        }
        
        return ans;
    }
};
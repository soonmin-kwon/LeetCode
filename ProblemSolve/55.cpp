/*************
 * Jump Game *
 *************/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums.size()-1;
        int dest = 0;
        
        //0번 인덱스부터 점프를 시작
        //n번 인덱스에서 nums[n]만큼 점프할 수 있기 때문에 for문 범위를 늘린다
        //0번 인덱스에서 3까지 점프할 수 있으면
        //for문을 1 ~ 3 까지 돌면서 최대 점프 거리를 체크한다.
        for(int i=0; i<= dest; i++){
            dest = max(i + nums[i], dest);
            if(dest >= last){
                return true;
            }
        }
        
        return false;
    }
};
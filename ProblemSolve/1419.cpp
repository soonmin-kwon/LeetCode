/************************************
 * Minimum Number of Frogs Croaking *
 ************************************/

// 참고 : https://leetcode.com/problems/minimum-number-of-frogs-croaking/discuss/586543/C%2B%2BJava-with-picture-simulation

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int len = croakOfFrogs.size();
        
        //애초에 불가능한 경우
        if(len % 5){
            return -1;
        }
        
        vector<int> count(5);
        int frogsCount = 0;
        int ans = 0;
        
        //개구리의 최소 마리수를 찾아야한다
        for(auto c : croakOfFrogs){
            //현재 char 값이 croak에서 몇번째 인덱스인지 확인
            auto idx = string("croak").find(c);
            
            //들어온 값을 idx에 맞춰서 카운트 해놓는다
            count[idx] += 1;
            
            //만약 c가 들어온 경우 가능한 개구리를 출근시킨다
            if(idx == 0){
                frogsCount++;
                //어쩔 수 없이 출근한 개구리의 최대 마리수를 저장
                ans = max(ans, frogsCount);
            }
            //c나 k가 들어오지 않은 경우 이전 값, croak중에 c, r, o, a 값이 유효한지 확인
            //만약 crook인 경우
            //두번째 o를 확인했을때 count[idx - 1] = 0, --count[idx - 1] = -1이 되므로 불가능한 case
            else if( --count[idx - 1] < 0){
                return -1;
            }
            //마지막인 경우 개구리 한마리를 퇴근시킨다
            else if(idx == 4){                
                frogsCount--;
            }
        }
        
        //만약 frogsCount가 0이 아닌경우 제대로 문자열이 끝나지 않았다는 걸 의미
        //고로 정상적인 문자열이 아니다
        return frogsCount == 0 ? ans : -1;
    }
};
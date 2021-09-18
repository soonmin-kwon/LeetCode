/*************************
 * Self Dividing Numbers *
 *************************/

class Solution {
public:
    //self dividing number인지 체크
    bool checkSelfDivided(int num){
        int temp = num;
        int dig;
        
        while(temp){
            //각 자리수를 저장하고
            dig = temp % 10;
            //그 자리수가 나눌 수 없는 경우이거나, num이 나눠지지 않으면 false
            if(dig == 0 || num % dig != 0){
                return false;
            }
            
            temp /= 10;
        }
        
        return true;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        
        //주어진 범위 내에 있는 모든 수를 검사하고
        //self dividing number면 정답에 추가한다
        for(int i=left; i<=right; i++){
            if(checkSelfDivided(i)){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
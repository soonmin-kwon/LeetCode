/************
 * Plus One *
 ************/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();        
        // 자리수가 바뀔 때 앞으로 insert하기 보다 뒤에 push 하는 게 효율적
        reverse(digits.begin(), digits.end());
        
        //끝 자리에 1을 더하고
        //다음 자리수에 영향을 주지 않으면 바로 break
        //다음 자리수에 영향을 주면 10이기 때문에 0으로 만들고 다음 자리수 + 1
        for(int i=0; i<len; i++){
            digits[i] +=1;
            if(digits[i] != 10){
                break;
            }
            else{
                digits[i] = 0;
            }
        }
        
        if(digits.back() == 0){
            digits.push_back(1);
        }
        
        reverse(digits.begin(), digits.end());
        
        return digits;
    }
};
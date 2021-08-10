/***************
 * Add Strings *
 ***************/

class Solution {
public:
    string addStrings(string num1, string num2) {
        //항상 num1이 더 길거나 같은 길이를 갖도록 변경
        if(num1.size() < num2.size()){
            string temp = num1;
            num1 = num2;
            num2 = temp;
        }
        
        reverse(num2.begin(), num2.end());
        
        int len1 = num1.size();
        int len2 = num2.size();
        
        //더 작은 입력을 더 큰 입력에 한자리씩 더해준다
        for(int i=0; i<len2; i++){
            num1[len1 - 1 - i] = num1[len1 - i - 1] + num2[i] - '0';                        
        }
        
        //10이 넘어간 값이 있으면 10을 빼주고 앞자리수에 1을 더해준다
        for(int i=len1 - 1; i>=1; i--){
            if(num1[i] > '9'){                
                num1[i] -= 10;
                num1[i-1] += 1;
            }
        }
        
        //마지막 자리가 10이 넘어가면 앞에 한 자리 추가
        if(num1[0] > '9'){
            num1[0] -= 10;
            num1 = '1' + num1;
        }
        
        return num1;        
    }
};
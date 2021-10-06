/********************************
 * Bitwise AND of Numbers Range *
 ********************************/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        //둘중에 하나라도 0이면 AND연산은 무조건 0이다
        if(left == 0 || right == 0){
            return 0;
        }
        
        //두값이 같으면 AND연산 결과는 자기 자신이 된다
        if(left == right){
            return right;
        }
                
        //두 값의 비트 수가 다르면  
        //두 값 사이에 반드시 모든 비트가 0이 된다
        //ex) 6, 9 -> 0110, 1001
        //  0 1 1 0
        //  0 1 1 1
        //  1 0 0 0
        //  1 0 0 1
        //= 0 0 0 0
        if((int)log2(left) != (int)log2(right)){
            return 0;
        }
        //비트의 수가 같은경우는 단순 and연산으로 계산한다
        else{
            int ans = left;
            
            for(unsigned int i=left+1; i<=right; i++){
                ans &= i;
            }
            
            return ans;
        }
    }
};
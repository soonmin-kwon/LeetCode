/*************************
 * Sum of Square Numbers *
 *************************/

class Solution {
public:
    bool judgeSquareSum(int c) {
        //a^2 + b^2 = c에서 a <= b라고 가정할때, b의 최대값을 구한다
        double temp = sqrt(c);
        
        long maxInt = (long)temp;   //b        
        long anotherInt = 0;        //a
        long sum;                   //c
        
        while(anotherInt <= maxInt){
            //a^2 + b^2 계산
            sum = anotherInt * anotherInt + maxInt * maxInt;
            
            //sum이 타겟보다 더 크면 b값 감소
            if(sum > c){
                maxInt--;
            }
            //sum이 타겟보다 작으면 a값 증가
            else if(sum < c){
                anotherInt++;
            }
            else{
                return true;
            }
        }
        
        return false;
    }
};
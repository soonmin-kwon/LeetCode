/****************
 * Happy Number *
 ****************/

class Solution {
public:
    //다음 수를 계산
    int calNext(int n){
        int temp = 0;
        while(n){
            temp += (n % 10) * (n % 10);
            n /= 10;
        }
        
        return temp;        
    }
    
    //참고 : https://leetcode.com/problems/happy-number/solution/
    bool isHappy(int n){
        int tortoise = n;
        int hare = calNext(n);
        
        //Tortoise & Hare Algorithm
        //사이클에 빠지면 1이 나올 수 없다
        while(hare != 1 && tortoise != hare){            
            tortoise = calNext(tortoise);
            hare = calNext(calNext(hare));
        }
        
        return hare == 1;
    }
    
    bool isHappy(int n) {
        int temp = 0;
        
        while(true){
            //다음 수 계산
            while(n){
                temp += (n % 10) * (n % 10);
                n /= 10;             
            }            
            
            //1이면 정답 7이어도 항상 1이 나오기 때문에 정답 처리
            if(temp == 1 || temp == 7){
                return true;
            }
            //그 외 1자리 수는 다 정답이 될 수 없음
            if(temp < 10){
                return false;
            }
            
            n = temp;
            temp = 0;
        }
        
        return false;
    }
};
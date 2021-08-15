/*****************************************************
 * Prime Number of Set Bits in Binary Representation *
 *****************************************************/

class Solution {
public:
    //Brian Kernighan's Algorithm
    int countSetBits(int n){
        int count = 0;
                
        //ex) 9
        //9 & 8 -> 1001 & 1000 = 1000
        //8 & 7 -> 1000 & 0111 = 0000
        while(n){
            n &= (n-1);
            count++;
        }
        
        return count;
    }
    
    bool checkPrime(int n){
        //input의 범위에 따라 나올 수 있는 소수의 종류 전부
        //input <= 1000000 = 1111 0100 0010 0100 0000
        if(n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19){
            return true;
        }
        
        return false;
    }
    
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        //범위에 들어가는 모든 수 검사
        for(int i=left; i <= right; i++){
            if(checkPrime(countSetBits(i))){
                ans++;
            }
        }
        
        return ans;
    }
};
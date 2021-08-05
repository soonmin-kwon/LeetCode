/****************
 * Count Primes *
 ****************/

class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        
        //에라토스테네스의 체
        if(n <= 1){
            return ans;
        }        
        
        bool* prime = new bool[n+1];
        
        for(int i=2; i<n; i++){
            prime[i] = true;
        }
        
        for(int i=2; i * i <n; i++){
            if(prime[i]){                                
                for(int j = i*i; j<=n; j+=i){
                    prime[j] = false;
                }
            }
        }
        
        //소수 개수 체크
        for(int i=2; i<n; i++){
            if(prime[i]){
                ans++;
            }
        }
        
        return ans;
    }
};
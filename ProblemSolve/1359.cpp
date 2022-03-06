/***********************************************
 * Count All Valid Pickup and Delivery Options *
 ***********************************************/

#define mod 1000000007

class Solution {
public:
    int countOrders(int n) {
        long long ans = 1;
        
        for(int i=1; i<=n; ++i){
            ans *= i;
            ans %= mod;
            
            ans *= (2*i - 1);
            ans %= mod;
        }
        
        return ans;
    }
};
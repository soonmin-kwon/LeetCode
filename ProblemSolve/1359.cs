/***********************************************
 * Count All Valid Pickup and Delivery Options *
 ***********************************************/

public class Solution {
    public int CountOrders(int n) {
        ulong mod = 1000000007;
        ulong ans = 1;
        
        for(uint i=1; i<=n; ++i){
            ans = ans * i;            
            ans %= mod;            
            ans = ans * (2*i - 1);
            
            ans %= mod;            
        }
        
        return (int)ans;
    }
}
/***********
 * Sqrt(x) *
 ***********/

class Solution {
public:
    int mySqrt(int x) {
        //오버플로우 방지
        long long start = 0, end = x;
        long long ans, mid;
        
        //Binary Search
        while(start <= end){
            mid = (start + end) / 2;
            if(mid * mid == x) {
                return mid;
            }
            else if(mid * mid < x){
                start = mid + 1;
                ans = mid;
            }
            else{
                end = mid -1;
            }
        }
        
        return ans;
    }
};
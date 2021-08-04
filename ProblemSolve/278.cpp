/*********************
 * First Bad Version *
 *********************/

class Solution {
public:            
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int mid;
        
        //binary search
        while(left < right){
            mid = left + (right - left) / 2;
            
            if(isBadVersion(mid)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        
        return left;
    }    
};
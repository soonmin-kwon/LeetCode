/***********************************************
 * Kth Smallest Number in Multiplication Table *
 ***********************************************/

// 참고 : https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/discuss/1580357/C%2B%2BPython-Clean-and-Simple-Solution-w-Detailed-Explanation-or-Binary-Search-with-Proof

class Solution {
public:
    bool isMidLessThanK(int m, int n, int mid, int k){
        int temp = 0;
        for(int i=1; i<=m; ++i){
            temp += min(mid/i, n);
        }
        
        return temp < k;
    }
    
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m*n, mid = 0, ans = 0;
        
        while(left <= right){
            mid = (left + right)/2;
            
            if(isMidLessThanK(m, n, mid, k)){
                left = mid + 1;
            }
            else{
                right = mid - 1;
                ans = mid;
            }
        }
        
        return ans;
    }
};
/**************************
 * Find K Closest Elements *
 **************************/

// 참고 : https://leetcode.com/problems/find-k-closest-elements/discuss/106426/JavaC%2B%2BPython-Binary-Search-O(log(N-K)-%2B-K)

public class Solution {
    public IList<int> FindClosestElements(int[] arr, int k, int x) {
        int left = 0, right = arr.Length - k;
        
        while(left < right){
            int mid = (left + right) / 2;
            
            if(x - arr[mid] > arr[mid + k] - x){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        
        return arr.ToList().GetRange(left, k);
    }
}
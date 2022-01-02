/*******************************************************
 * Pairs of Songs With Total Durations Divisible by 60 *
 *******************************************************/

public class Solution {
    public int NumPairsDivisibleBy60(int[] time) {
        int[] hash = new int[60];
        int ans = 0;
        
        for(int i=0; i<time.Length; ++i){
            ans += hash[(60 - (time[i] % 60)) % 60];
            hash[time[i] % 60]++;
        }
        
        return ans;
    }
}
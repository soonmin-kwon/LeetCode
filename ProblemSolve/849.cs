/***************************************
 * Maximize Distance to Closest Person *
 ***************************************/

public class Solution {
    public int MaxDistToClosest(int[] seats) {
        int[] distToClosestPerson = new int[seats.Length];        
        
        int prevIdx = 0;
        int ans = 0;
        
        for(int i=0; i<seats.Length; ++i){
            if(seats[i] == 0){
                distToClosestPerson[i] = i == 0 ? Int32.MaxValue : i - prevIdx;
            }
            else{
                prevIdx = i;
            }
        }

        prevIdx = seats.Length;
        for(int i=seats.Length-1; i>=0; --i){
            if(seats[i] == 1){
                prevIdx = i;
            }

            distToClosestPerson[i] = Math.Min(distToClosestPerson[i], prevIdx == seats.Length ? distToClosestPerson[i] : prevIdx - i);
            ans = Math.Max(ans, distToClosestPerson[i]);
        }
        
        return ans;
    }
}
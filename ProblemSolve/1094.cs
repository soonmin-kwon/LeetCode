/***************
 * Car Pooling *
 ***************/

public class Solution {
    public bool CarPooling(int[][] trips, int capacity) {                
        if(trips[0][0] > capacity){
            return false;
        }
        
        int[] schedule = new int[1001];
        int end = 0;
        
        //스케쥴을 미리 만들어서 타고 내리는 사람 수를 계산해놓는다
        for(int i=0; i<trips.Length; ++i){
            end = Math.Max(end, trips[i][2]);
            
            schedule[trips[i][1]] += trips[i][0];
            schedule[trips[i][2]] -= trips[i][0];
        }
        
        //불가능한 경우가 발생하면 return false
        for(int i=0; i<=end; ++i){
            capacity -= schedule[i];
            
            if(capacity < 0){
                return false;
            }
        }
        
        return true;
    }
}
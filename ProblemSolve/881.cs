/************************
 * Boats to Svae People *
 ************************/

public class Solution {
    public int NumRescueBoats(int[] people, int limit) {
        Array.Sort(people);
        Array.Reverse(people);
        int ans = 0;
        int frontIdx = 0, backIdx = people.Length - 1;

        while(frontIdx <= backIdx){
            int weight = people[frontIdx];
            frontIdx++;
            
            if(weight + people[backIdx] <= limit){
                weight += people[backIdx];
                backIdx--;
            }
            
            ans++;
        }
        
        return ans;
    }
}
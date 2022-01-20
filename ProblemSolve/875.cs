/***********************
 * KoKo Eating Bananas *
 ***********************/

public class Solution {
    public int MinEatingSpeed(int[] piles, int h) {
        int left = 1;
        int right = 0;
        
        foreach(int pile in piles){
            right = Math.Max(pile, right);
        }
        
        while(left < right){
            int middle = (left + right) / 2;
            int totalHour = 0;
            
            foreach(int pile in piles){
                totalHour += (pile / middle) + (pile % middle != 0 ? 1 : 0);
            }
            
            if(totalHour <= h){
                right = middle;
            }
            else{
                left = middle + 1;
            }
        }
        
        return right;
    }
}
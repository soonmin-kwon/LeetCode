/**************
 * Add Digits *
 **************/

public class Solution {
    public int AddDigits(int num) {
        int tempSum = 0;
        
        while(num >= 10){
            tempSum += num % 10;
            num /= 10;
            
            if(num < 10){
                tempSum += num;
                num = tempSum;
                tempSum = 0;
            }
        }
        
        return num;
    }
}
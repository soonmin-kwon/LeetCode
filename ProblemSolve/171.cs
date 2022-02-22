/*****************************
 * Excel Sheet Column Number *
 *****************************/

public class Solution {
    public int TitleToNumber(string columnTitle) {
        int ans = 0;
        int columnPower = 1;
        for(int i=columnTitle.Length-1; i>=0; --i){
            int colNum = (int)(columnTitle[i] - 'A') + 1;
            ans += (colNum * columnPower);
            columnPower *= 26;
        }
        
        return ans;
    }
}
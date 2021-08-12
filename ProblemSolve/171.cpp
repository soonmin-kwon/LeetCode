/*****************************
 * Excel Sheet Column Number *
 *****************************/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int len = columnTitle.size();
        int ans = 0;
        int power = 1;
        
        //끝자리부터 체크하면서 값을 더해나간다
        for(int i=len-1; i>=0; i--){
            ans += power * (columnTitle[i] - 'A' + 1);
            
            if(i == 0){
                return ans;
            }
            power *= 26;
        }
        
        return ans;
    }
};
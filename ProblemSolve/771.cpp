/*********************
 * Jewels and Stones *
 *********************/

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        //jewel에 들어있는 char 저장
        vector<bool> jewelHash(256);
        int ans = 0;
        
        //jewels에 들어있는 char을 저장한다
        for(char jewel : jewels){
            jewelHash[(int)jewel] = true;
        }
        
        //stones의 char을 모두 확인하면서 jewels에 속한 char이 몇개인지 센다
        for(char stone : stones){
            if(jewelHash[(int)stone]){
                ans++;
            }
        }
        
        return ans;
    }
};
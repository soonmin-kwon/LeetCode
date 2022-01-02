/*******************************************************
 * Pairs of Songs With Total Durations Divisible by 60 *
 *******************************************************/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> hash(60);
        int ans = 0;
        
        for(int t : time){
            //% 60을 한 번 더 해야 60이 0이랑 매칭.
            //60은 60이랑도 매칭돼도 되고 0이랑도 매칭돼도 되지만
            //0으로만 매칭되게끔 해서 계산한다
            ans += hash[(60 - (t % 60)) % 60];
            hash[t % 60]++;
        }
        
        return ans;
    }
};
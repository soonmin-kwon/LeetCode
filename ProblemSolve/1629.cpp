/***************
 * Slowest Key *
 ***************/

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {        
        int len = releaseTimes.size();
        //각 key의 최대 releaseTime을 저장
        int duration[26] = {0, };
        
        //line : 13 ~ 18 을 진행하면서 keysPressed에 있는 모든 char의 최대 releaseTime을 저장한다
        duration[keysPressed[0] - 'a'] = releaseTimes[0];
        char ans;        
        
        for(int i=1; i<len; i++){
            duration[keysPressed[i] - 'a'] = max(duration[keysPressed[i] - 'a'], (releaseTimes[i] - releaseTimes[i-1]));
        }
        
        int temp = -1;

        //가장 큰 releaseTime을 갖는 char을 찾는다
        //사전의 역순으로 찾아야 하기 때문에 도중에 break를 하지 않는다.
        for(int i=0; i<26; i++){
            if(temp <= duration[i]){
                temp = duration[i];
                ans = i + 'a';
            }
        }
        
        return ans;
    }
};
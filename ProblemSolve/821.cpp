/************************************
 * Shortest Distance to a Character *
 ************************************/

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {        
        int len = s.size();
        int targetIdx = -len;
        
        vector<int> ans(len);
        
        //왼쪽에 있는 target으로부터 가장 가까운 거리를 계산한다
        for(int i=0; i<len; i++){
            if(s[i] == c){
                targetIdx = i;
            }
            
            //처음 target이 나오기 전에는 이 값은 26 line의 min에 영향을 줘서는 안 되기 때문에
            //len의 길이보다 큰 값이 저장되게 된다.
            ans[i] = i - targetIdx;
        }
        
        //오른쪽에 있는 target으로부터 가장 가까운 거리를 계산하고
        //바로 바로 최소값을 확인하면서 왼쪽에 더 가까운지, 오른쪽에 더 가까운지 확인한다
        for(int i=targetIdx-1; i>=0; i--){
            if(s[i] == c){
                targetIdx = i;
            }
            
            ans[i] = min(ans[i], targetIdx - i);
        }
        
        return ans;
    }
};
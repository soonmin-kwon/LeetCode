/*****************
 * Rotate String *
 *****************/

class Solution {
public:
    //KMP Algorithm
    vector<int> getPi(string goal){
        int len = goal.size();
        int j = 0;
        
        vector<int> pi(len, 0);
        
        for(int i=1; i<len; i++){
            while(j>0 && goal[i] != goal[j]){
                j = pi[j-1];
            }
            
            if(goal[i] == goal[j]){
                pi[i] = ++j;
            }
        }
        
        return pi;
    }
    
    bool rotateString(string s, string goal) {
        int lenS = s.size();
        int lenG = goal.size();
        
        if(lenS != lenG){
            return false;
        }
        
        vector<int> pi = getPi(goal);
        
        //s + s로 만들면 rotate된 문자열이 s에 들어가 있게된다
        s += s;
        lenS *= 2;
        int count = 0;
        
        for(int i=0; i<lenS; i++){
            while(count > 0 && s[i] != goal[count]){
                count = pi[count - 1];
            }
            
            if(s[i] == goal[count]){
                if(count == lenG - 1){
                    return true;
                }
                else{
                    count++;
                }
            }
        }
        
        return false;        
    }
};
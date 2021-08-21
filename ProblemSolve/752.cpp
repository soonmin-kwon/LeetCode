/*****************
 * Open the Lock *
 *****************/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        //hash table
        unordered_set<string> uset(deadends.begin(), deadends.end());
        unordered_set<string> prev;
        
        queue<string> q;
        
        //deadends에 0000이 있으면 무조건 invalid
        if(uset.find("0000") != uset.end()){
            return -1;
        }
        
        int depth = 0;
        int len;
        string temp;
        char spell;
        //시작 다이얼
        q.push("0000");
        prev.insert("0000");
        
        while(!q.empty()){
            len = q.size();
            
            //현재 q에 있는 모든 값에 대해 진행
            //depth를 각 경우의 수마다 저장하는 것으로 설계하지 않았기 때문에 이렇게 진행
            //이렇게 하면 이번 for문에서 접근하는 모든 q의 element는 같은 depth를 갖는다
            for(int i=0; i<len; i++){
                temp = q.front();
                q.pop();
                
                if(temp == target){
                    return depth;
                }
                
                //각 자리수의 변화를 계산
                for(int j=0; j<4; j++){
                    spell = temp[j];
                    
                    //1씩 빼는 경우
                    //0일 때는 9로 변경
                    temp[j] = spell == '0' ? '9' : spell - 1;
                    
                    //hash table에 없으면서 처음 만든 경우의수인 경우                    
                    if(uset.find(temp) == uset.end() && prev.find(temp) == prev.end()){
                        q.push(temp);
                        prev.insert(temp);
                    }
                    
                    //1씩 더하는 경우
                    //9일 때는 0으로 변경
                    temp[j] = spell == '9' ? '0' : spell + 1;
                    if(uset.find(temp) == uset.end() && prev.find(temp) == prev.end()){
                        q.push(temp);
                        prev.insert(temp);
                    }
                    
                    temp[j] = spell;
                }
            }
            
            depth++;
        }
        
        return -1;
    }
};
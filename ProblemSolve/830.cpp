/*****************************
 * Positions of Large Groups *
 *****************************/

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        vector<int> temp;
        char prev = s[0];
        int len = s.size();
        int end = 0, start = 0;
        
        for(int i=1; i<len; i++){
            //end값 갱신
            //현재 i 값이 다른 값이면 i-1까지가 같은 문자열
            end = i - 1;
            
            //문자열이 다른 경우
            if(s[i] != prev){
                //조건에 부합하면
                if(end - start >= 2){
                    //temp에 push_back
                    temp.push_back(start);
                    temp.push_back(end);
                    
                    ans.push_back(temp);    //정답에 push_back
                    
                    temp.clear();   //temp 초기화
                }
                //prev, start값 갱신
                prev = s[i];
                start = i;                
            }
        }
                
        //끝에 남아있는 값 추가
        if(end + 1 - start >= 2){
            temp.push_back(start);
            temp.push_back(end + 1);
            ans.push_back(temp);
        }
        
        return ans;        
    }
};
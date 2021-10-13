/**************************
 * Print Words Vertically *
 **************************/

class Solution {
public:
    //공백을 기준으로 문자열 분리
    vector<string> split(vector<string>& splited, string target){
        stringstream ss(target);
        string temp;
        
        while(getline(ss, temp, ' ')){
            splited.push_back(temp);
        }
        
        return splited;
    }
    
    vector<string> printVertically(string s) {
        vector<string> ans;
        int idx = 0;
        int maxLength = 0;
        
        vector<string> splited;        
        //공백 기준 문자열 분리
        split(splited, s);
        
        //가장 긴 문자열을 찾아서 그 문자열 만큼 정답에 추가해야 한다
        for(int i=0; i<splited.size(); i++){
            maxLength = max(maxLength, (int)splited[i].size());
        }
        
        for(int i=0; i<maxLength; i++){
            string temp = "";            
            for(int j=0; j<splited.size(); j++){
                //splited[j]의 범위를 벗어나면 공백 추가
                if(idx >= splited[j].size()){
                    temp += ' ';                       
                }
                //벗어나지 않으면 char 추가
                else{
                    temp += splited[j][idx];
                }
            }
            
            //끝에 생기는 공백 제거
            while(temp.back() == ' '){
                temp.pop_back();
            }
            
            ans.push_back(temp);
            idx++;
        }
        
        return ans;
    }
};
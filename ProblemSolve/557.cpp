/*********************************
 * Reverse Words in a String III *
 *********************************/

class Solution {
public:
    string reverseWords(string s) {
        //공백을 기준으로 분리하기 위한 준비
        stringstream ss(s);
        vector<string> splited;
        
        //공백을 기준으로 문자열 분리
        while(ss.good()){
            string splits;
            getline(ss, splits, ' ');
            splited.push_back(splits);
        }
        
        //분리된 문자열을 각각 뒤집어준다
        for(auto &splits : splited){
            for(int i=0; i<splits.size() / 2; i++){
                swap(splits[i], splits[splits.size()-1-i]);
            }
        }
        
        string ans="";
        
        //마지막 문자열의 경우 공백을 추가하지 않으면서 정답 문자열을 만든다
        for(int i=0; i<splited.size(); i++){
            ans += splited[i];
            if(i != splited.size()-1){
                ans += ' ';
            }
        }
                
        return ans;
    }
};
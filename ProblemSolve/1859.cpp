/************************
 * Sorting the Sentence *
 ************************/

class Solution {
public:
    //끝자리에 있는 순서에 맞춰 정렬
    static bool compare(string& a, string& b){
        int seqA = a.back() - '0';
        int seqB = b.back() - '0';
        
        return seqA < seqB;
    }
    
    string sortSentence(string s) {
        //공백으로 분리한 문자열 저장
        vector<string> splits;
        
        string ans = "";
        int start = 0;
        
        for(int i=1; i<s.size(); i++){
            if(s[i] == ' '){
                //공백을 만나면 공백 이전 문자열 저장
                splits.push_back(s.substr(start, i - start));
                start = i+1;
            }
        }
        //마지막 문자열 저장
        splits.push_back(s.substr(start, s.size() - start));
        
        //끝자리에 있는 순서에 맞춰 정렬
        sort(splits.begin(), splits.end(), compare);
        
        //모든 문자열 더하기
        for(auto st : splits){
            ans += st.substr(0, st.size() - 1);
            
            //마지막 문자열이 추가되면 공백이 없어야 함
            if(st == splits[splits.size() - 1]){
                break;
            }
                        
            ans += ' ';     //공백 추가
        }
        
        return ans;
    }
};
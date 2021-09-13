/**************************
 * Find Common Characters *
 **************************/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        //words에 들어있는 문자열들에 존재하는 char의 개수를 센다
        vector<int> countMem(26, INT_MAX);                
        
        for(auto word : words){            
            vector<int> countChar(26);
            
            //각 단어별로 char 개수를 세서            
            for(auto ch : word){
                countChar[ch - 'a']++;
            }
            
            //최소 값을 저장한다
            //만약 다른 단어에서 이전에 나왔던 char 값이 나오지 않으면 0으로 바뀌게 된다
            for(int i=0; i<26; i++){
                countMem[i] = min(countMem[i], countChar[i]);
            }
        }
        
        vector<string> ans;
        
        //0이 아닌 값만큼 해당하는 char를 string 타입으로 바꿔 저장한다
        for(int i=0; i<26; i++){
            if(countMem[i] > 0){
                for(int x=0; x<countMem[i]; x++){
                    ans.push_back(string(1, i + 'a'));
                }                
            }            
        }
        
        return ans;
    }
};
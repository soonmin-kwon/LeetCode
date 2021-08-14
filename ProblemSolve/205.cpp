/**********************
 * Isomorphic Strings *
 **********************/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //바꿔야 하는 두 character쌍 저장
        unordered_map<char, char> change;
        
        //이미 등장했는지 확인
        unordered_map<char, bool> check;
        
        int len = s.size();
                
        for(int i=0; i<len; i++){
            //이미 특정 값으로 바뀌어야 된다는 게 결정됐는지 확인
            auto it1 = change.find(s[i]);
            auto it2 = check.find(t[i]);
            
            if(it1 != change.end()){
                //이미 존재하는 chracter면 제대로 바뀌는지 확인
                if(change[s[i]] != t[i]){
                    return false;
                }
            }
            //존재 하지 않는 chracter일 때
            else{
                //한번 나왔던 chracter면 다른 값이랑 매치되는 값
                if(it2 != check.end()){
                    return false;
                }
                //두 character 모두 처음 나오면 값 생성
                else{
                    change[s[i]] = t[i];
                    check[t[i]] = true;
                }
            }
        }
        
        return true;
    }
};
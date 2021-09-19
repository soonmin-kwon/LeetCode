/*********************************************
 * Check If Two String Arrays are Equivalent *
 *********************************************/

class Solution {
public:
    //한 string 배열을 하나의 string으로 만들어 다른 배열과 비교한다
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string temp ="";
        int idx = 0;
        
        //하나의 string으로 만들기
        for(auto word : word1){
            temp += word;
        }
        
        //다른 배열에 들어있는 string들과 하나로 만든 string을 비교한다
        //idx를 따로 만들어 하나로 만든 string을 순서대로 탐색한다
        //순서가 맞지 않으면 false
        for(auto word : word2){
            for(auto ch : word){
                if(temp[idx] != ch){
                    return false;
                }
                idx++;
            }
        }
        
        //두 배열에 들어있는 string들의 길이의 합이 다른 경우에는 idx 값이 temp.size() 값이 아니게 된다
        if(idx != temp.size()){
            return false;
        }
        
        return true;
    }
};
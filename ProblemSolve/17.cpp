/*****************************************
 * Letter Combinations of a Phone Number *
 *****************************************/

class Solution {
public:
    //재귀로 정답에 들어갈 경우의 수 모두 탐색
    void makeAns(vector<string>& keyboard, vector<string>& ans, string curStr, string input){
        //입력으로 들어온만큼 길이가 늘어나면 정답에 추가
        if(curStr.size() == input.size()){
            ans.push_back(curStr);
            return;
        }
        
        //현재 curStr의 길이가 2면 input의 2번째 idx에 접근해야 함        
        int idx = curStr.size();
        
        //접근해야 하는 input에 맞춰서 for문을 돈다
        //ex) input = "243"일때 idx = 1이면 keyboard[4]만큼 for문을 돈다
        for(int i=0; i<keyboard[input[idx] - '0'].size(); i++){
            curStr = curStr + keyboard[input[idx] - '0'][i];
            makeAns(keyboard, ans, curStr, input);
            curStr.pop_back();
        }
    }
        
    vector<string> letterCombinations(string digits) {
        //keyboard 배열 저장
        vector<string> keyboard = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> ans;
        if(digits.empty()){
            return ans;
        }
        
        makeAns(keyboard, ans, "", digits);
        
        return ans;
    }
};
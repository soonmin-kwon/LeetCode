/***********************************************
 * Find Words That Can Be Formed by Characters *
 ***********************************************/

class Solution {
public:
    //주어진 chars에서 각 char의 개수를 세고
    //words의 word마다 char의 개수를 세서 주어진 조건에 부합하는지 확인 후 정답에 추가
    int countCharacters(vector<string>& words, string chars) {
        vector<int> countChars(26);
        bool canBeFormed = true;
        int ans = 0;
        
        //주어진 chars에서 각 char의 개수를 센다
        for(char ch : chars){
            countChars[ch-'a']++;
        }
        
        //words의 word마다 
        for(string word : words){
            vector<int> countWordChars(26);
            
            //char의 개수를 세서 
            for(char ch : word){
                countWordChars[ch-'a']++;
                
                //주어진 조건에 부합하는지 확인 후 
                if(countChars[ch-'a'] < countWordChars[ch-'a']){
                    canBeFormed = false;
                    break;
                }
            }
            
            //정답에 추가
            if(canBeFormed){
                ans += word.size();
            }
            canBeFormed = true;
        }
        
        return ans;
    }
};
/***********************************************
 * Find Words That Can Be Formed by Characters *
 ***********************************************/

public class Solution {
    public int CountCharacters(string[] words, string chars) {
        int[] countChars = new int[26];             //주어진 chars의 char마다 개수 세기, 일종의 hash
        bool canBeFormed = true;                    //만들 수 있는지
        int ans = 0;
        
        //개수 세기
        foreach(char ch in chars){
            countChars[ch - 97]++;
        }
        
        foreach(string word in words){
            int[] countWordChars = new int[26];
            //각 단어마다 char의 개수를 세서 주어진 chars로 만들 수 있는지 확인
            //chars의 주어진 개수보다 많이 써야하는 경우 false
            foreach(char ch in word){
                countWordChars[ch - 97]++;
                
                if(countChars[ch-97] < countWordChars[ch-97]){
                    canBeFormed = false;
                    break;
                }
            }
            
            if(canBeFormed){                
                ans += word.Length;
            }
            
            canBeFormed = true;
        }
        
        return ans;
    }
}
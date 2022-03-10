/*****************************************
 * Letter Combinations of a Phone Number *
 *****************************************/

public class Solution {
    public void Backtracking(List<string> keypad, ref List<string> ans, string currLetter, string input){
        if(currLetter.Length == input.Length){
            ans.Add(currLetter);
            return;
        }
        
        int idx = currLetter.Length;
        
        for(int i=0; i<keypad[input[idx] - '0'].Length; ++i){
            currLetter += keypad[input[idx] - '0'][i];
            Backtracking(keypad, ref ans, currLetter, input);
            currLetter = currLetter.Remove(currLetter.Length - 1, 1);
        }
        
        return;
    }
    
    public IList<string> LetterCombinations(string digits) {
        List<string> keypad = new List<string>(){"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        List<string> ans = new List<string>();
        
        if(digits.Length == 0){
            return ans;
        }
        
        Backtracking(keypad, ref ans, "", digits);
        
        return ans;
    }
}
/****************************
 * Remove Duplicate Letters *
 ****************************/

public class Solution {
    public int Back(StringBuilder sb){
        return (int)sb[sb.Length - 1];
    }
    
    public void PopBack(ref StringBuilder sb){
        sb.Remove(sb.Length-1, 1);
    }
    
    public string RemoveDuplicateLetters(string s) {
        int[] candidate = new int[256];
        bool[] visitied = new bool[256];
        
        foreach(char ch in s){
            candidate[(int)ch]++;
        }
        
        StringBuilder sb = new StringBuilder();
        sb.Append('0');
        
        foreach(char ch in s){
            candidate[(int)ch]--;
            
            if(visitied[(int)ch]){
                continue;
            }
            
            while((int)ch < Back(sb) && candidate[Back(sb)] > 0){
                visitied[Back(sb)] = false;
                PopBack(ref sb);
            }
            
            sb.Append(ch);
            visitied[(int)ch] = true;
        }
        sb.Remove(0,1);
        
        return sb.ToString();
        
    }
}
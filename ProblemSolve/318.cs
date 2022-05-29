/***********************************
 * Maximum Product of Word Lengths *
 ***********************************/

public class Solution {
    public bool isSame(BitArray a, BitArray b){
        for(int i=0; i<26; ++i){
            if(a[i] && b[i]){
                return true;
            }
        }
        
        return false;
    }
    
    public int MaxProduct(string[] words) {
        int ans = 0;
        
        List<BitArray> check = new List<BitArray>();
        for(int i=0; i<words.Length; ++i){
            check.Add(new BitArray(26));
        }
        
        for(int i=0; i<words.Length; ++i){
            foreach(char ch in words[i]){
                check[i][(int)(ch - 'a')] = true;
            }
            
            for(int j=0; j<i; ++j){
                if(!isSame(check[i], check[j])){
                    ans = Math.Max(ans, words[i].Length * words[j].Length);
                }
            }
        }
        
        return ans;
    }
}
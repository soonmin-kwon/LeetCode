/***************
 * N-Queens II *
 ***************/

public static class StringExtension{
    public static string ReplaceAt(this string input, int index, char newChar)
    {
        if (input == null)
        {
            throw new ArgumentNullException("input");
        }
        char[] chars = input.ToCharArray();
        chars[index] = newChar;
        return new string(chars);
    }
}

public class Solution {
    int ans = 0;
    
    bool CheckCanPut(int col, int row, int n, List<string> chess){
        for(int i=0; i<row; ++i){
            if(chess[i][col] == 'Q'){
                return false;
            }
            
            for(int j=0; j<n; ++j){
                if(chess[i][j] == 'Q' && Math.Abs(i-row) == Math.Abs(j - col)){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    public void NQueen(int n, int row, ref List<string> chess){
        if(n == row){
            ans++;
            return;
        }
        
        for(int i=0; i<n; ++i){
            chess[row] = chess[row].ReplaceAt(i, 'Q');
            
            if(CheckCanPut(i, row, n, chess)){
                NQueen(n, row+1, ref chess);
            }
            
            chess[row] = chess[row].ReplaceAt(i, '.');
        }
    }
    
    public int TotalNQueens(int n) {
        if(n <= 3){
            if(n == 1){
                return 1;
            }
        }
           
        List<string> chess = new List<string>();
        
        for(int i=0; i<n; ++i){
            chess.Add(new String('.', n));
        }
        
        NQueen(n, 0, ref chess);
                    
        return ans;
    }
}
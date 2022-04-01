/******************
 * Reverse String *
 ******************/

public class Solution {
    public void Swap(ref char left, ref char right){
        char temp = left;
        left = right;
        right = temp;
    }
    
    public void ReverseString(char[] s) {
        int left = 0, right = s.Length-1;
        
        while(left < right){
            Swap(ref s[left], ref s[right]);
            left++;
            right--;
        }
        
        return;
    }
}
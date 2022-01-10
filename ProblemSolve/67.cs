/**************
 * Add Binary *
 **************/

public class Solution {
    public string AddBinary(string a, string b) {        
        if(a.Length < b.Length){
            string temp = a;
            a = b;
            b = temp;
        }
        
        var ans = new StringBuilder();
        int gap = a.Length - b.Length;
        int idx = a.Length-1;
        int carry = 0;

        //두 string 길이 맞추기        
        for(int i=0; i<gap; ++i){
            b = '0' + b;
        }
                
        while(idx >= 0){
            //비트 값 구하기
            var bitValue = a[idx] - '0' + b[idx] - '0' + carry;                        
            
            if(bitValue >= 2){
                carry = 1;
                ans.Insert(0, bitValue - 2);
            }
            else{
                carry = 0;
                ans.Insert(0, bitValue);
            }
            
            idx--;
        }                
        
        //남은 carry 값 계산
        if(carry != 0){
            Console.WriteLine(carry);
            ans.Insert(0, carry);
        }
        
        return ans.ToString();
    }
}
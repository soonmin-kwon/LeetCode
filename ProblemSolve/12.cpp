class Solution {
public:
    //큰 자리수부터 확인 : 0 ms
    string intToRoman(int num) {
        string ans ="";
        string temp ="";        
        //미리 배열에 만들 수 있는 기본적인 수 들을 만들어 놓고 뽑아쓴다.
        string cases[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int digit[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        
        while(num != 0){                        
            for(int i=12; i>=0; i--){ 
                while(num >= digit[i] ){
                    num -= digit[i];
                    ans += cases[i];
                }             
            }            
        }
        
        return ans;
    }
    
    //작은 자리수부터 확인 : 4ms
    string intToRoman(int num) {
        string ans ="";
        string temp ="";
        int inp, idx = 0;
        string cases[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int digit[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        
        while(num != 0){
            inp = (num % 10) * (int)(pow(10,idx));
            num /= 10;
            
            for(int i=12; i>=0; i--){                
                while(inp >= digit[i] ){
                    inp -= digit[i];
                    temp += cases[i];
                }             
            }
            ans = temp + ans;
            temp = "";
            idx++;
        }
        
        return ans;
    }
};
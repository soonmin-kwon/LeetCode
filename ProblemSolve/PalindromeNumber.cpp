class Solution {
public:
    bool isPalindrome(int x) {
        //Follow up에 맞춰서 string을 사용하지 않는다.
        //음수면 무조건 false
        if(x < 0) {
            return false;
        }
        
        int temp = x;
        int length = 0;
        
        //자리수 체크
        while(temp != 0) {
            temp = temp/10;
            length++;            
        }
        //자리수에 따라 나눠줘야 할 수 설정
        int indexing = (int)pow(10, length-1);
        
        //1의자리 수와 가장 큰자리 수를 비교하면서 다르면 false
        for(int i = length -1; i>0; i-=2){
            if( x / indexing == x % 10 ) {                
                x = x % indexing;
                x = x / 10;
                indexing = indexing / 100;
            }else{
                return false;
            }
        }
        
        return true;
    }
};
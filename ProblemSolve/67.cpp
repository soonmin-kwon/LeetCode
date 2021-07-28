/**************
 * Add Binary *
 **************/

class Solution {
public:
    string addBinary(string a, string b) {        
        int len, len2;
        //a가 항상 길도록 설정
        if(a.size() <= b.size()){
            string temp = a;
            a = b;
            b = temp;            
        }                
        //더하는 string을 역순으로 만들어 더하기 쉽게 한다.
        reverse(b.begin(), b.end());
        
        len = a.size();
        len2 = b.size();
        
        //한자리 한자리 다 더한다.
        for(int i=0; i<len2; i++){
            a[len-i-1] = a[len-i-1] - '0' + b[i];
        }

        //끝 자리부터 체크하면서 2보다 크면 2를 빼주고 다음 자리수에 1을 올린다.
        for(int i=len-1; i>=1; i--){
            if(a[i] >= '2'){
                a[i] -= 2;
                a[i-1] += 1;
            }
        }
        
        //마지막 자리수가 2보다 크면 한자리 추가.
        if(a[0] >= '2'){
            a[0] -= 2;
            a = '1' + a;
        }
                
        return a;
    }
};
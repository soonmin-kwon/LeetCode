/**************************
 * K-th Symbol in Grammar *
 **************************/

class Solution {
public:
    //n번째 row의 앞쪽 절반은 n-1번째 줄과 같다
    //n번째 row의 뒤쪽 절반은 앞쪽 절반을 뒤집은(0을 1로, 1을 0으로) 것과 같다
    int kthGrammar(int n, int k) {
        if(n == 1 && k == 1){
            return 0;
        }
        
        //절반이 몇개인지 계산
        int mid = pow(2, n - 1) / 2;
        
        //앞쪽 절반에 있으면 이전 줄에서 결과를 찾을 수 있다
        if(mid >= k){
            return kthGrammar(n-1, k);
        }
        //뒤쪽 절반에 있으면 이전 줄에서 결과를 찾을 수 있지만 값을 뒤집어줘야 한다
        else{
            //만약 k가 mid + a라고 가정했을 때 값은
            //a번째 값을 뒤집은 값이다
            //고로 k - mid번째 값을 찾으면 된다
            return !kthGrammar(n-1, k - mid);
        }
        
        return 1;
    }
};
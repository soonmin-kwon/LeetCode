/********************
 * Hamming Distance *
 ********************/

public class Solution {
    public int HammingDistance(int x, int y) {
        //xor연산을 해서 서로 다른 비트를 1로 바꿈
        int xorXY = x^y;
        int ans = 0;

        //Brian Kernighan's Algorithm
        //비트가 1인 자리수의 개수를 센다
        while(xorXY > 0){
            xorXY &= (xorXY-1);
            ans++;
        }
        
        return ans;
    }
}
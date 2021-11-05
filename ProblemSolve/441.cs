/*******************
 * Arranging Coins *
 *******************/

public class Solution {
    public int ArrangeCoins(int n) {
        int ans = 0;
        //k를 ans라고 했을 때
        //sqrt(2n + 1/4) - 3/2 < k <= sqrt(2n + 1/4) - 1/2를 만족하는 정수 k가 정답
        //sqrt(2n + 1/4) - 3/2 + 1 = sqrt(2n + 1/4) - 1/2이므로
        //sqrt(2n + 1/4) - 1/2에 int로 형변환 해주면 k를 구할 수 있다.
        ans = (int)(Math.Sqrt((2*(long)n) + 0.25) - 0.5);
        
        return ans;
    }
}
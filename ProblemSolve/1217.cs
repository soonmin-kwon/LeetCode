/***************************************************
 * Minimum Cost to Move Chips to The Same Position *
 ***************************************************/

public class Solution {
    //짝수 칸 만큼 이동하는 건 공짜
    //홀수에서 짝수로, 짝수에서 홀수로 갈 때만 비용 발생.
    //홀수, 짝수 개수를 세서 더 적은 수 만큼 옮기면 정답.
    public int MinCostToMoveChips(int[] position) {
        int oddCnt = 0, evenCnt = 0;
        
        foreach(int num in position){
            if(num % 2 == 0){
                ++evenCnt;
            }
            else{
                ++oddCnt;
            }
        }
        
        return Math.Min(oddCnt, evenCnt);
    }
}
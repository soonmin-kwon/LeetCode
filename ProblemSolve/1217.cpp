/***************************************************
 * Minimum Cost to Move Chips to The Same Position *
 ***************************************************/

class Solution {
public:
    //짝수 칸 만큼 이동하는 건 공짜
    //홀수에서 짝수로, 짝수에서 홀수로 갈 때만 비용 발생.
    //한번만 발생하면 그 이후로 공짜. 홀수, 짝수 개수를 세서 더 적은 수 만큼 옮기면 정답.
    int minCostToMoveChips(vector<int>& position) {
        int oddCount = 0, evenCount = 0;
        for(int num : position){
            if(num % 2){
                oddCount++;
            }
            else{
                evenCount++;
            }
        }
        
        return min(oddCount, evenCount);
    }
};
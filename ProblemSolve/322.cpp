/***************
 * Coin Change *
 ***************/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        //i 금액을 만드는 데 필요한 최소한의 동전의 수 저장
        //0 <= amount  <= 10^4
        vector<int> cost(amount + 1, 10001);
        
        //0번째 인덱스는 기본값 0으로 설정
        cost[0] = 0;
        //coin[i]번째부터 진행하면서 
        //현재 금액 j를 만드는데 필요한 최소 동전 수는
        //현재 금액을 만드는데 필요한 최소 동전 수와 현재 금액에서 coins[i]만큼 뺀 금액을 만드는데 필요한 최소 동전 수 + 1
        for(int i=0; i<len; i++){
            for(int j=coins[i]; j<=amount; j++){
                cost[j] = min(cost[j], cost[j-coins[i]] + 1);
            }
        }
        
        //amount 만큼의 금액을 만드는데 필요한 최소 동전 개수가 기존값이랑 같으면 -1 리턴
        if(cost[amount] == 10001){
            return -1;
        }
        
        return cost[amount];
    }
};
/******************
 * Ugly Number II *
 ******************/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumbers(n + 1, 1);
        
        int pointerTwo = 1, pointerThree = 1, pointerFive = 1;      //Pointer가 가리키는 곳에 2, 3, 5를 곱한다. Pointer는 각각의 기준에 맞춰 제일 작은 수를 가리킨다
        int candidateTwo, candidateThree, candidateFive;            //i번째 ugly number가 될 수 있는 후보군들, 2, 3, 5를 곱한 값을 의미
        int elect;                                                  //i번째 ugly number의 값
        
        //n까지 for문을 돌면서 ugly number를 구한다
        for(int i=2; i<=n; i++){
            candidateTwo = 2 * uglyNumbers[pointerTwo];
            candidateThree = 3 * uglyNumbers[pointerThree];
            candidateFive = 5 * uglyNumbers[pointerFive];
            
            elect = min({candidateTwo, candidateThree, candidateFive});
            
            uglyNumbers[i] = elect;
            
            //ex) i == 2인 경우, cadidateTwo, candidateThree, candidateFive는 각각, 2, 3, 5이다
            //elect는 2이고 pointerTwo가 증가한다
            //i == 3의 경우 elect는 3, i == 4, i == 5인 경우는 각각 4, 5이다
            //i == 6인 경우, candidateTwo, Three, Five는 각각 6, 6, 10이다.
            //겹치는 수는 하나의 수로 판단하기 때문에 else if문이 아닌 각각 if문을 이용한다
            if(elect == candidateTwo){
                pointerTwo++;
            }
            
            if(elect == candidateThree){
                pointerThree++;
            }
            
            if(elect == candidateFive){
                pointerFive++;
            }                        
        }
        
        return uglyNumbers[n];
    }
};
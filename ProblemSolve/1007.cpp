/******************************************
 * Minimum Domino Rotations For Equal Row *
 ******************************************/

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> countTops(7);       //tops에 있는 domino의 숫자를 센다
        vector<int> countBottoms(7);    //bottoms에 있는 domino의 숫자를 센다
        vector<int> countSame(7);       //tops[i]와 bottoms[i]가 같으면 count한다
        
        int ans = -1;
        
        for(int i=0; i<tops.size(); i++){            
            if(tops[i] == bottoms[i]){
                countSame[tops[i]]++;
            }
            
            countTops[tops[i]]++;
            countBottoms[bottoms[i]]++;
        }
        
        for(int i=1; i<7; i++){
            //countTops[i] + countBottoms[i] = 모든 i의 개수
            //countTops[i] + countBottoms[i] - countSame[i] = 한 줄에 있을 수 있는 i의 개수
            //따라서 tops.size()와 비교해서 같다면 정답 후보군 중 하나
            //가장 작은 rotation의 수를 찾아야 하기 때문에 더 조금 움직이는 방법은
            //더 조금 있는 열에서 더 많이 있는 열로 옮기는 것이다
            if(countTops[i] + countBottoms[i] - countSame[i] == tops.size()){
                ans = max((int)tops.size() - max(countTops[i], countBottoms[i]), ans);
            }
        }
        
        return ans;
    }
};
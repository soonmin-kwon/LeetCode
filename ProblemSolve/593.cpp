/****************
 * Valid Square *
 ****************/

class Solution {
public:
    //거리를 계산, root를 모두 씌우지 않은 상태에서 비교해도 상관이 없기 때문에 sqrt 적용 x
    double dist(vector<int>& p1, vector<int>& p2){
        return (p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> system;
        
        //좌표 4개를 x 좌표값을 우선시해서 정렬하면 좌표 4개의 위치를 고정할 수 있고
        //네 변의 길이, 대각선의 길이를 특정할 수 있다.   
        //참고 : https://leetcode.com/problems/valid-square/solution/ 
        //Approach #2 그림
        system.push_back(p1);
        system.push_back(p2);
        system.push_back(p3);
        system.push_back(p4);
        
        sort(system.begin(), system.end());
        
        double dist1, dist2, dist3, dist4;
        
        //각 변의 길이 계산, 저장
        dist1 = dist(system[0], system[1]);
        dist2 = dist(system[0], system[2]);
        dist3 = dist(system[2], system[3]);
        dist4 = dist(system[1], system[3]);
        
        double diagonal1, diagonal2;
        
        //각 대각선의 길이 계산 저장
        diagonal1 = dist(system[1], system[2]);
        diagonal2 = dist(system[0], system[3]);
        
        //길이가 0이면 정사각형 x, 네 변의 길이가 같고, 두 대각선의 길이가 같으면 정사각형
        return dist1 != 0 && dist1 == dist2 && dist2 == dist3 && dist3 == dist4 && diagonal1 == diagonal2;
        
    }
};
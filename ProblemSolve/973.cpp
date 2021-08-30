/******************************
 * K Closest Points to Origin *
 ******************************/

//참고 : https://leetcode.com/problems/k-closest-points-to-origin/discuss/217966/C%2B%2B-3-lines-nth_element-O(n)

class Solution {
public:
    //O(n)
    //nth_element를 이용한 해답
    //179ms, 49.2 MB
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {        
        //거리 순으로 k-1번째 index까지 정렬
        nth_element(points.begin(), points.begin() + k - 1, points.end(), 
                   [](vector<int>& a, vector<int>& b){
                       return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
                   });
        
        //필요 없는 부분 삭제
        points.resize(k);
        
        return points;
    }
    
    //O(n log n)
    //sort를 이용한 해답
    //277ms, 49.2 MB
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        //거리 순으로 정렬
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
                       return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
                   });
        
        
        //필요 없는 부분 삭제
        points.resize(k);
        
        return points;
    }
};
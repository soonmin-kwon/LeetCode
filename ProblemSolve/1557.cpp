/*************************************************
 * Minimum Number of Vertices to Reach All Nodes *
 *************************************************/

//참고 : https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/discuss/805701/C%2B%2B-No-Traversal-Required-or-O(n)-or-Clean-Solution

class Solution {
public:
    //directed acyclic graph이기 때문에 indegree, outdegree가 따로 존재한다
    //현재 vertex에 indegree가 존재하면 다른 vertex에서 현재 vertex로 접근이 가능하다는 소리
    //indegree가 존재하지 않으면 그 vertex는 outdegree가 있거나 다른 vertex에 접근이 불가한 vertex이다.
    //고로 indegree가 없는 vertex를 찾으면 그 vertex를 통해서 모든 vertex에 도달할 수 있다.
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> hash;
        vector<int> ans;
        
        //indegree가 있는 vertex 정보 저장
        for(auto edge : edges){
            hash.insert(edge[1]);
        }
        
        //indegree가 없는 vertex를 정답에 추가
        for(int i=0; i<n; i++){
            if(hash.find(i) == hash.end()){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
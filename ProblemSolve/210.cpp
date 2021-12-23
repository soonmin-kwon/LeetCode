/**********************
 * Course Schedule II *
 **********************/

//참고 : https://jackpot53.tistory.com/85
//     : https://leetcode.com/problems/course-schedule-ii/discuss/892071/Solution-based-on-Kahn's-Algorithm(Detailed-Explantion)

class Solution {
public:
    //topological sort
    bool khan(vector<vector<int>>& graph, int nodeLength, vector<int>& indegree, vector<int>& ans){
        queue<int> q;
        
        for(int i=0; i<nodeLength; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        int count = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(int next : graph[node]){
                --indegree[next];
                if(indegree[next] == 0){
                    q.push(next);
                }
            }
            
            count++;
        }
        
        if(count != nodeLength){
            return false;
        }
        
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int len = prerequisites.size();
        
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        
        for(int i=0; i<len; i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]] += 1;
        }
        
        vector<int> ans;
        
        if(khan(graph, numCourses, indegree, ans)){
            return ans;
        }
        
        return {};
    }
};
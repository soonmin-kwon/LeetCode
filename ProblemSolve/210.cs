/**********************
 * Course Schedule II *
 **********************/

//참고 : https://jackpot53.tistory.com/85
//     : https://leetcode.com/problems/course-schedule-ii/discuss/892071/Solution-based-on-Kahn's-Algorithm(Detailed-Explantion)

public class Solution {
    public bool khan(ref List<int>[] graph, ref int[] indegree, ref List<int> ans, int nodeLength){
        Queue<int> q = new Queue<int>();
        
        for(int i=0; i<nodeLength; ++i){
            if(indegree[i] == 0){
                q.Enqueue(i);
            }
        }
        
        int count = 0;
        
        while(q.Count > 0){
            int node = q.Dequeue();
            ans.Add(node);
            
            if(graph[node] != null){
                foreach(int next in graph[node]){
                    --indegree[next];
                    if(indegree[next] == 0){
                        q.Enqueue(next);
                    }
                }
            }
            
            ++count;
        }
        
        if(count != nodeLength){
            return false;
        }
        
        return true;
    }
    
    public int[] FindOrder(int numCourses, int[][] prerequisites) {
        int len = prerequisites.Length;
        
        List<int>[] graph = new List<int>[numCourses];
        int[] indegree = new int[numCourses];
        List<int> ans = new List<int>();
        
        for(int i=0; i<len; ++i){
            if(graph[prerequisites[i][1]] == null){
                graph[prerequisites[i][1]] = new List<int>();
            }
            
            graph[prerequisites[i][1]].Add(prerequisites[i][0]);
            indegree[prerequisites[i][0]] += 1;
        }
        
        if(khan(ref graph, ref indegree, ref ans, numCourses)){
            return ans.ToArray();
        }
        
        return new int[] {};
    }
}
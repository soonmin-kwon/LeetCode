/************************
 * Redundant Connection *
 ************************/

public class Solution {    
    public int[] parent = null;     //각 node의 부모 배열
    
    public int findParent(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    
    public bool hasSameParent(int node1, int node2){
        node1 = findParent(node1);
        node2 = findParent(node2);
        
        if(node1 == node2){
            return true;
        }
        
        return false;
    }
    
    public void unionNode(int node1, int node2){
        node1 = findParent(node1);
        node2 = findParent(node2);
        
        if(node1 != node2){
            parent[node2] = node1;
        }
    }
    
    public int[] FindRedundantConnection(int[][] edges) {
        parent = new int[edges.Length + 1];
        //부모 초기화
        for(int i=0; i<=edges.Length; i++){
            parent[i] = i;
        }
        
        foreach(var edge in edges){
            //부모가 다르면 Union, 부모가 같으면 cycle이 생기는 상황이기 때문에 그 edge를 빼야한다
            if(!hasSameParent(edge[0], edge[1])){
                unionNode(edge[0], edge[1]);
            }
            else{
                return edge;
            }
        }
        
        return new int[]{};
    }
}
/***************
 * Clone Graph *
 ***************/

/*
// Definition for a Node.
public class Node {
    public int val;
    public IList<Node> neighbors;

    public Node() {
        val = 0;
        neighbors = new List<Node>();
    }

    public Node(int _val) {
        val = _val;
        neighbors = new List<Node>();
    }

    public Node(int _val, List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

public class Solution {
    Dictionary<Node, Node> copiedNodes = new Dictionary<Node, Node>();
    
    public Node CloneGraph(Node node) {
        if(node == null){
            return null;
        }
        
        if(copiedNodes.ContainsKey(node) == true){
            return copiedNodes[node];
        }
        
        copiedNodes[node] = new Node(node.val);
        foreach(Node neighbor in node.neighbors){
            copiedNodes[node].neighbors.Add(CloneGraph(neighbor));
        }
        
        return copiedNodes[node];
    }
}
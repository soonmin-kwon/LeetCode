/*****************
 * Baseball Game *
 *****************/

public class Solution {
    public int CalPoints(string[] ops) {
        Stack<int> operation = new Stack<int>();
        for(int i=0; i<ops.Length; ++i){
            if(ops[i] == "+"){
                int prev1 = operation.Pop();
                int prev2 = operation.Pop();
                int newElement = prev1 + prev2;
                operation.Push(prev2);
                operation.Push(prev1);
                operation.Push(newElement);
            }
            else if(ops[i] == "D"){
                int prev = operation.Pop();
                operation.Push(prev);
                operation.Push(prev * 2);
            }
            else if(ops[i] == "C"){
                operation.Pop();
            }
            else{
                operation.Push(Int32.Parse(ops[i]));
            }
            
        }
        
        int ans = 0;
        while(operation.Count > 0){
            ans += operation.Pop();
        }
        
        return ans;
    }
}
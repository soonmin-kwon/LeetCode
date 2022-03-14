/*****************
 * Simplify Path *
 *****************/

public class Solution {
    public string SimplifyPath(string path) {
        string[] paths = path.Split('/');
        Stack<string> pathBuilder = new Stack<string>();
        
        for(int i=0; i<paths.Length; i++){
            if(paths[i].Equals("..")){
                if(pathBuilder.Count != 0){
                    pathBuilder.Pop();
                }
                
                continue;
            }
            
            if(paths[i].Equals(".") || paths[i].Equals("")){
                continue;
            }

            pathBuilder.Push(paths[i]);
        }
        
        StringBuilder ans = new StringBuilder();
        
        while(pathBuilder.Count != 0){
            string p = pathBuilder.Pop();
            if(p.Equals("/")){
                continue;
            }
            
            ans.Insert(0, "/" + p);
        }
        
        if(ans.Length != 0 && ans[ans.Length - 1] == '/'){
            ans.Remove(ans.Length-1, 1);
        }
        
        if(ans.Length == 0){
            return "/";
        }
        
        return ans.ToString();
    }
}
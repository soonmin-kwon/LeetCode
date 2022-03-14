/*****************
 * Simplify Path *
 *****************/

class Solution {
public:
    vector<string> split(string s, char delimiter){
        vector<string> splited;
        stringstream ss(s);
        string temp;
    
        while (getline(ss, temp, delimiter)) {
            splited.push_back(temp);
        }
 
        return splited;
    }
    
    string simplifyPath(string path) {
        stack<string> pathStack;
        vector<string> paths = split(path, '/');
        
        for(int i=0; i<paths.size(); ++i){
            if(paths[i] == ".."){
                if(!pathStack.empty()){
                    pathStack.pop();
                }
                continue;
            }
            
            if(paths[i] == "." || paths[i] == ""){
                continue;
            }
            
            pathStack.push(paths[i]);
        }
        
        string ans = "";
        
        while(!pathStack.empty()){
            string p = pathStack.top();
            pathStack.pop();
            if(p == "/"){
                continue;
            }
            
            ans = "/" + p + ans;
        }
        
        if(ans.length() != 0 && ans[ans.length() - 1] == '/'){
            ans.pop_back();
        }
        
        if(ans.length() == 0){
            return "/";
        }
        
        return ans;
    }
};
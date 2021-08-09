/************************
 * Generate Parenthesis *
 ************************/

class Solution {
public:
    //재귀적으로 괄호를 생성
    void makeParenthesis(vector<string>& ans, string cur, int left, int right, int n){
        //여는 괄호, 닫는 괄호가 만들려는 만큼 있으면 정답에 추가
        if(left == n && right == n){
            ans.push_back(cur);
            return;
        }
        
        //닫는 괄호가 여는 괄호보다 많으면 잘못된 괄호
        if(right > left){
            return;
        }        
        
        //여는 괄호가 더 많을 때
        if(left > right){
            //여는 괄호가 최대치가 아니면
            if(left != n){
                //여는 괄호를 추가해줘도 된다
                makeParenthesis(ans, cur + '(', left+1, right, n);
            }
            //여는 괄호가 더 많기 때문에 닫는 괄호를 추가해준다.            
            makeParenthesis(ans, cur + ')', left, right+1, n);            
        }
                
        //여는 괄호와 닫는 괄호가 같은 수만큼 있으면 무조건 여는 괄호가 나와야 함
        if(left == right) {
            makeParenthesis(ans, cur + '(', left + 1, right, n);
        }
                              
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        makeParenthesis(ans, "(", 1, 0, n);
        
        return ans;
    }
};
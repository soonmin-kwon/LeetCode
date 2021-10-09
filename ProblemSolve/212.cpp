/******************
 * Word Search II *
 ******************/

class Trie {
private:
    struct Node{
        //알파벳 26가지 저장
        Node* child[26];
        //입력한 단어의 끝인지
        bool isEnd;
        //중복 방지
        int count = 0;
    };
    
public:
    Node* node;
    
    Trie() {
        node = new Node();
    }
    
    void insert(string word) {
        Node* cur = node;
        
        //입력한 단어를 한 character씩 저장
        for(auto ch : word){
            if(cur -> child[ch - 'a'] == NULL){
                cur -> child[ch - 'a'] = new Node();
            }
            
            //cur을 cur -> child로 바꿔서 다음 character가 그대로 이어질 수 있도록 한다
            cur = cur -> child[ch - 'a'];
        }
        //단어를 모두 입력하면 단어의 끝으로 설정
        cur -> isEnd = true;
    }
    
    bool search(string word) {
        Node* cur = node;
        
        for(auto ch : word){
            //찾는 단어의 character가 child에 없으면 false
            if(cur -> child[ch - 'a'] == NULL){
                return false;
            }
            
            //위의 insert와 동일
            cur = cur -> child[ch - 'a'];
        }                
        
        //한번 search된 단어면 정답에 들어가기 때문에 중복 방지 위해 count 1로 설정
        cur -> count ++;
        
        //입력한 단어인지, 다른 단어의 중간에 도착한건지 확인
        //count가 1일때만 처음 search한 단어
        return ((cur -> isEnd) && (cur -> count == 1));
    }
    
    bool startsWith(string prefix) {
        Node* cur = node;
        
        //prefix로 시작하는 단어가 있는지 확인
        //search처럼 진행
        //for문이 정상적으로 끝나면 prefix로 시작하는 단어가 trie에 있다는 뜻
        for(auto ch : prefix){
            if(cur -> child[ch - 'a'] == NULL){
                return false;
            }
            cur = cur -> child[ch - 'a'];
        }
        
        return true;
    }
};

class Solution {    
public:
    int maxRow, maxCol;
    
    //주어진 board 위를 한칸씩 이동하면서 trie에 있는 단어인지 확인한다
    //curWord가 search되면 정답에 추가한다
    void dfs(Trie& trie, vector<vector<char>>& board, vector<string>& ans, string curWord, int r, int c){
        
        //범위를 벗어났거나 이미 왔던 칸으로 되돌아간 경우 바로 return
        if(r < 0 || r >= maxRow || c < 0 || c >= maxCol || board[r][c] == 0){
            return;
        }
        
        //검색하려는 단어 갱신
        curWord += board[r][c];
        
        //현재 단어로 시작하는 단어가 trie에 없으면 찾을 수 없는 단어이다
        if(!trie.startsWith(curWord)){
            return;
        }
        
        //현재 단어를 trie에서 찾을 수 있으면 정답에 추가
        if(trie.search(curWord)){
            ans.push_back(curWord);
        }
        
        //backtracking
        board[r][c] = 0;
        
        dfs(trie, board, ans, word, r + 1, c);
        dfs(trie, board, ans, word, r - 1, c);
        dfs(trie, board, ans, word, r, c + 1);
        dfs(trie, board, ans, word, r, c - 1);
        
        board[r][c] = word.back();
        
        return;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie = Trie();
        vector<string> ans;
        
        maxRow = board.size();
        maxCol = board[0].size();
        
        for(auto word : words){
            trie.insert(word);
        }
        
        for(int i=0; i<maxRow; i++){
            for(int j=0; j<maxCol; j++){                
                dfs(trie, board, ans, "", i, j);
                //이미 다 찾은경우 정답 return
                if(ans.size() >= words.size()){
                    return ans;
                }
            }
        }
        
        return ans;
    }
};
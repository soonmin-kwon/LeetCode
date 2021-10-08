/********************************
 * Implement Trie (Prefix Tree) *
 ********************************/

class Trie {
private:
    struct Node{
        //알파벳 26가지 저장
        Node* child[26];
        //입력한 단어의 끝인지
        bool isEnd;       
    };
    
    Node* node;
    
public:
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
        
        //입력한 단어인지, 다른 단어의 중간에 도착한건지 확인
        return cur -> isEnd;
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
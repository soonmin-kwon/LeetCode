/****************************
 * Prefix and Suffix Search *
 ****************************/

class TrieNode {
public:
    TrieNode* children[27];
    int weight;
    
    TrieNode() {
        for(int i=0; i<=26; ++i){
            children[i] = NULL;
        }
        weight = 0;
    }
};

class WordFilter {
public:
    TrieNode* trieNode;
    WordFilter(vector<string>& words) {
        trieNode = new TrieNode();
        
        for(int i=0; i<words.size(); ++i){
            string word = words[i] + '{';
            
            for(int a = 0; a < word.size(); ++a){
                TrieNode* curr = trieNode;
                curr -> weight = i;
                
                for(int b = a; b<2*word.size() - 1; ++b){
                    int ch = word[b % word.size()] - 'a';
                    
                    if(curr -> children[ch] == NULL){
                        curr -> children[ch] = new TrieNode();
                    }
                    
                    curr = curr -> children[ch];
                    curr -> weight = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        TrieNode* currNode = trieNode;
        
        for(auto& ch : suffix + "{" + prefix){
            if(currNode -> children[ch - 'a'] == NULL){
                return -1;
            }
            
            currNode = currNode -> children[ch - 'a'];
        }
        
        return currNode -> weight;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
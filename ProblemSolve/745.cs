/****************************
 * Prefix and Suffix Search *
 ****************************/

public class TrieNode {
    public TrieNode[] children;
    public int weight;
    
    public TrieNode(){
        children = new TrieNode[27];
        weight = 0;
    }
}

public class WordFilter {
    TrieNode trieNode;
    
    public WordFilter(string[] words) {
        trieNode = new TrieNode();
        
        for(int i=0; i<words.Length; ++i){
            string word = words[i] + "{";
            
            for(int j=0; j<word.Length; ++j){
                TrieNode curr = trieNode;
                curr.weight = i;
                
                for(int k = j; k < 2 * word.Length - 1; ++k){
                    int ch = (int)(word[k % word.Length] - 'a');
                    
                    if(curr.children[ch] == null){
                        curr.children[ch] = new TrieNode();                        
                    }
                    
                    curr = curr.children[ch];
                    curr.weight = i;
                }
            }
        }
    }
    
    public int F(string prefix, string suffix) {
        TrieNode curr = trieNode;
        foreach(char ch in (suffix + "{" + prefix)){
            if(curr.children[(int)(ch - 'a')] == null){
                return -1;
            }
            
            curr = curr.children[(int)(ch - 'a')];
        }
        
        return curr.weight;
    }
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.F(prefix,suffix);
 */
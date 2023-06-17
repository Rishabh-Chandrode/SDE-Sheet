
class TrieNode{
    public:
        TrieNode *child[26];
        bool isword;
        TrieNode(){
            isword = false;
            for(auto &a:child) a = NULL;
        }
};

class Trie {
private:
   TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *currnode = root;
        int n = word.size();
        for(int i=0;i<n;i++){
            if(currnode->child[word[i]-'a'] == NULL){
                currnode->child[word[i]-'a'] = new TrieNode();
            }
            currnode = currnode->child[word[i]-'a'];
        }

        currnode->isword = true;
    }
    
    bool search(string word) {
        TrieNode *currnode = root;
        int n = word.size();
        for(int i=0;i<n;i++){
            if(currnode->child[word[i]-'a'] == NULL){
                return false;
            }
            currnode = currnode->child[word[i]-'a'];
        }

        return currnode->isword;
    }
    
    bool startsWith(string prefix) {
         TrieNode *currnode = root;
        int n = prefix.size();
        for(int i=0;i<n;i++){
            if(currnode->child[prefix[i]-'a'] == NULL){
                return false;
            }
            currnode = currnode->child[prefix[i]-'a'];
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
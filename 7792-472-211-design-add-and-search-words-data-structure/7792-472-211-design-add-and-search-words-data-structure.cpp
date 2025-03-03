class Node {
public:
    Node* mp[27];
    bool end;
    vector<int> dot;
    Node() : end(false) {  
        for(int i = 0; i < 26 ;i ++){
            mp[i] = nullptr;
        }
    }

};
class WordDictionary {
public:
    Node* root = new Node();;
    WordDictionary() {
    }

    void addWord(string word) {
        Node* temp = root;
        for(char x: word){
            if(!temp->mp[x - 'a']){
                Node* newnode = new Node();
                temp->mp[x - 'a'] = newnode;
                temp->dot.push_back(x - 'a');
                temp = newnode;
            }else{
                temp->dot.push_back(x - 'a');
                temp = temp->mp[x - 'a'];
            }
        }
        temp->end = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
    bool dfs(const string& word, int index, Node* node) {
        if (!node) return false;
        if (index == word.size()) return node->end;

        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->mp[i] && dfs(word, index + 1, node->mp[i])) {
                    return true;
                }
            }
        } else {
            return dfs(word, index + 1, node->mp[ch - 'a']);
        }
        return false;
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
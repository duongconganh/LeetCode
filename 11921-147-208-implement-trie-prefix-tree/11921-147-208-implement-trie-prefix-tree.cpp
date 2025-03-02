class Node {
public:
    Node* mp[27];
    bool end;
    Node() : end(false) {  
        for(int i = 0; i < 26 ;i ++){
            mp[i] = nullptr;
        }
    }

};

class Trie {
public:
    Node* root = new Node();
    Trie() {
        
    }
    void insert(string word) {
        Node* temp = root;
        for(char x: word){
            if(!temp->mp[x - 'a']){
                Node* newnode = new Node();
                temp->mp[x - 'a'] = newnode;
                temp = newnode;
            }else{
                temp = temp->mp[x - 'a'];
            }
        }
        temp->end = true;

    }
    
    bool search(string word) {
        Node* temp = root;
        for(char x: word){
            if(!temp -> mp[x - 'a']){
                return false;
            }
            temp = temp->mp[x - 'a'];
        }
        return temp->end;

    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(char x: prefix){
            if(!temp -> mp[x - 'a']){
                return false;
            }
            temp = temp->mp[x - 'a'];
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
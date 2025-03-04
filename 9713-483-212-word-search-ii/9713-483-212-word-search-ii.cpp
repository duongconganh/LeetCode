#include <execution>

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Node {
public:
    Node* mp[26];
    bool end;
    Node() : end(false) {  
        for(int i = 0; i < 26 ;i ++){
            mp[i] = nullptr;
        }
    }
    bool search(char c){return mp[c - 'a'] != nullptr;}
};
class Solution {
    int dir[5] = {0,-1,0,1,0};
    bool check;
    vector<vector<int>> vs;
    int n, m;
    Node* root;
    vector<string> ans;
    unordered_map<string, bool> map;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ans.clear();
        map.clear();
        n = board.size();
        m = board[0].size();
        root = new Node();
        vector<vector<int>> visit(n ,vector<int>(m , 0));
        for(string x: words){
            addWord(x);
        }
        Node* temp;
        string s;
        vs = visit;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m ; j ++){
                temp = root;
                if(temp ->search(board[i][j])){
                    vs[i][j] = 1;
                    s = board[i][j];
                    dfs(i , j, temp->mp[board[i][j] - 'a'] , s, board);
                    vs[i][j] = 0;                    
                }
                if(map.size() == words.size()){
                    return ans;
                }
            }
        }
        return ans;
    }
    void dfs(int x, int y, Node* temp ,string word, vector<vector<char>>& board){

        if(temp->end && map.find(word) == map.end()){
            map[word] = true;
            ans.push_back(word);
        }
        
        int a, b;
        string s;
        for(int k = 0; k < 4; k ++){
            a = x + dir[k];
            b = y + dir[k + 1];
            if(a >= 0 && a < n && b >= 0 && b < m && vs[a][b] == 0 && temp->search(board[a][b])){
                vs[a][b] = 1;
                s = board[a][b];
                dfs(a, b,temp-> mp[board[a][b] - 'a'], word + s, board);
                vs[a][b] = 0;
            }
        }
        return;
    }
    void addWord(string word) {
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
};
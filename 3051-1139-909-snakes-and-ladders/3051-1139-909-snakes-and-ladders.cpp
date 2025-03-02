class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();
        int m = board[0].size();
        int temp = 0;
        queue<int> q;
        q.push(0);
        int ans = 0;
        vector<int> vs(n* m, 0);
        while(!q.empty()){
            ans++;
            int size = q.size();
            for(int i = 0;i < size;i ++){
                temp = q.front();
                q.pop();
                int last = -1;;
                for(int j = 1;j <= 6 ;j ++){
                    int xt = temp + j;
                    if(xt == n*n - 1){
                        return ans;
                    }

                    int x = (n - 1 - xt/n);
                    int y =  (xt/(n) % 2 == 0)?( xt % n):(n - 1 - xt% n);
                    if(board[x][y] > 0 && vs[board[x][y] - 1] == 0){
                        vs[board[x][y] - 1] = 1;
                        q.push(board[x][y] - 1);
                        if(board[x][y] == n*n){
                            return ans;
                        }
                    }
                    if(board[x][y] == -1){
                        last = xt;
                    }
                   
                }
                if(last != -1){
                    q.push(last);
                }
            }

        }
        return -1;
    }
};

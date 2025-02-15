class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int live,die;
        int n = board.size();
        int m = board[0].size();
        int x,y;
        for(int i = 0;i < n; i++){
            for(int j = 0;j < m; j++){
                live = 0;
                die = 0;

                for(int k = 0; k < 8; k++){
                    x = i + dx[k] ;
                    y = j + dy[k];
                    if(x >= 0 && x < n && y >= 0 && y < m){
                        if(board[x][y] >= 1){
                            live ++;
                        }else{
                            die ++;
                        }
                    }

                }
                if(board[i][j] == 0 && live == 3){
                    board[i][j] = -1;
                }
                if(board[i][j] == 1){
                    if(live < 2 || live > 3){
                        board[i][j] = 2;
                    }

                }
            //    cout<<live<<" "<<die<<"|";

            }

        }
        for(int i = 0;i < n; i++){
            for(int j = 0;j < m; j++){
                if(board[i][j] == 2){
                    board[i][j] = 0;
                }else if(board[i][j] == -1){
                    board[i][j] = 1;
                }
            }
        }
        
    }
};
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ;i < 9;i ++){
            vector<int> check(9,0);
            for(int j = 0;j < 9 ;j ++){
                if(isdigit(board[i][j])){
                    if(check[board[i][j] - '1'] > 0){
                        return false;
                    }
                    check[board[i][j] - '1'] ++;
                }
            }
        }

        for(int i = 0 ;i < 9;i ++){
            vector<int> check(9,0);
            for(int j = 0;j < 9 ;j ++){
                if(isdigit(board[j][i])){
                    if(check[board[j][i] - '1'] > 0){
                        return false;
                    }
                    check[board[j][i] - '1'] ++;
                }
            }
        }
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                vector<int>freq(9,0);
               for(int k=0;k<3;k++)
               {
                 for(int l=0;l<3;l++)
                  {
                     if(board[i+k][j+l]!='.')
                      {
                        if(freq[board[i+k][j+l]-'1']==1) return false;
                       freq[board[i+k][j+l]-'1']=1; 
                      }
                  }
               }
                   
            }
        }


        return true;
    }
};
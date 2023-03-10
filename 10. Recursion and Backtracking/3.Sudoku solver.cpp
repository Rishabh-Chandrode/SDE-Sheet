class Solution {
public:
    bool isvalid(int x,int y,char c,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[x][i] == c) return false;
            if(board[i][y] == c) return false;
            if (board[3 * (x / 3) + i / 3][3 * (y / 3) + i % 3] == c) return false;
        }
        return true;
    }
    
    bool solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char c = '1' ; c<='9';c++){
                        if(isvalid(i,j,c,board)) {\
                            board[i][j] = c;
                            if(solveSudoku(board)){
                                return true;
                            }else{
                                board[i][j] = '.';

                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};
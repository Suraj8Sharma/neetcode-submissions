class Solution {
public:
  bool is_safe(vector<vector<char>>&board,int row,int col,int digit){
        //checking the horizontal
        for(int i =0;i<9;i++){
            if(board[row][i]==digit){
                return false;
            }
        }
            //for vertical
        for(int i =0;i<9;i++){
                if(board[i][col]==digit){
                return false;
            }
        }
        //now we need to check for the individual 3*3 that it does not have any repetion
        int sr=(row/3)*3;
        int sc=(col/3)*3;
        //doing a 3*3 check 
        for (int i =sr;i<sr+2;i++){
            for(int j =sc;j<sc+2;j++){
                if(board[i][j]==digit){
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
   int m=board.size();
        int n=board[0].size();
      for(int i =0;i<m;i++){
        for(int  j=0;j<n;j++){
            if(board[i][j]!='.'){
                //now i need to check 
                int temp=board[i][j];
                board[i][j]='.';
                if(is_safe(board,i,j,temp)){
                    board[i][j]=temp;
                }else{
                  return   false;
                }
            }
        }
      }  
   return true; }
};

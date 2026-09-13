class Solution {
public:
void dfs(int i ,int j ,int m,int n ,vector<vector<char>>&board){
    if(i<0||i>=m||j<0||j>=n||board[i][j]=='X'||board[i][j]=='H'){
        return ;
    }
    board[i][j]='H';
    dfs(i+1,j,m,n,board);
    dfs(i-1,j,m,n,board);
    dfs(i,j+1,m,n,board);
    dfs(i,j-1,m,n,board);
}
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
       //from the four edges we need to run the loop
       for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0||j==0||i==m-1||j==n-1){
                dfs(i,j,m,n,board);
            }
        }
        
       }

        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='H'){
                    board[i][j]='O';
                }
            
            }
        }
    }
};
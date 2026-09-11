class Solution {
public:
    void dfs(int row,int col,int m,int n,vector<vector<char>>&grid){
        if(row<0 ||  row>=m||col<0||col>=n||grid[row][col]=='0'){
            return ;
        }
        grid[row][col]='0';
        dfs(row+1,col,m,n,grid);
        dfs(row-1,col,m,n,grid);
        dfs(row,col+1,m,n,grid);
        dfs(row,col-1,m,n,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int islands=0;
        for(int  i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    dfs(i,j,m,n,grid);
                }
            }
        }
  return islands;
    }
};
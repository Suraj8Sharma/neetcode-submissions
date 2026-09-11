class Solution {
public:
    int dfs(int &count,int row,int col,int m,int n ,vector<vector<int>>&grid){
        if(row<0 || row>=m ||col<0 ||col>=n||grid[row][col]==0){
            return 0;
        }
        grid[row][col]=0;
        count++;
         dfs(count,row+1,col,m,n,grid);
        dfs(count,row-1,col,m,n,grid);
        dfs(count,row,col-1,m,n,grid);
        dfs(count,row,col+1,m,n,grid);
        return count ;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n =grid[0].size();
        int maxarea=0;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int count=0;
                    int area=dfs(count,i,j,m,n,grid);
                    maxarea=max(area,maxarea);
                }
            }
        }
    return maxarea;}
};
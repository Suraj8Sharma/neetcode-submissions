class Solution {
public:
void dfs(int i ,int j ,int m ,int n,vector<vector<bool>>&ocean,vector<vector<int>>&heights,int prevheight){

    if(i<0||i>=m||j<0||j>=n||ocean[i][j]==true||heights[i][j]<prevheight){
        return ;
    }
    ocean[i][j]=true;
    dfs(i+1,j,m,n,ocean,heights,heights[i][j]);
    dfs(i-1,j,m,n,ocean,heights,heights[i][j]);
    dfs(i,j+1,m,n,ocean,heights,heights[i][j]);
    dfs(i,j-1,m,n,ocean,heights,heights[i][j]);
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //the main idea is that we find out that to pacific from where wehre we can go 
        int m=heights.size();
        int n =heights[0].size();
        vector<vector<bool>>pacific(m,vector<bool>(n,false));
        vector<vector<bool>>atlantic(m,vector<bool>(n,false));

        //now we will for the pacific from top and left
        for(int i=0;i<n;i++){
            dfs(0,i,m,n,pacific,heights,heights[0][i]);

        }
        for(int i =0;i<m;i++){
            dfs(i,0,m,n,pacific,heights,heights[i][0]);
        }

        //for the atlantic ocean water can come only from the right and bottom 
        for(int i=0;i<n;i++){
            dfs(m-1,i,m,n,atlantic,heights,heights[m-1][i]);
        }

        for(int i=0;i<m;i++){
            dfs(i,n-1,m,n,atlantic,heights,heights[i][n-1]);
        }

     vector<vector<int>>ans;
     for(int i=0;i<m;i++){
        for(int j =0;j<n;j++){
            if(pacific[i][j]&& atlantic[i][j]){
                ans.push_back({i,j});
            }
        }
     }   
    return ans;}
};
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
     int m=grid.size();
     int n=grid[0].size();
     int INF = 2147483647;
     //for bfs we need to maintain a queue
     queue<pair<int,int>>q;
    
    for(int i =0;i<m;i++){
        for(int j =0;j<n;j++){
            if(grid[i][j]==0){
                q.push({i,j});
            }
        }
    }
    // we have intialized the queue 
    //now in bfs we move in 4  direcion at once 
        int nr[] = {0, 0, 1, -1};
        int nc[] = {1, -1, 0, 0};

    //expand the queue
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            pair<int,int>curr=q.front();
            q.pop();
            int row=curr.first;
            int col=curr.second;
            for(int j=0;j<4;j++){
                int new_row=row+nr[j];
                int new_col=col+nc[j];
                if(new_row<0 || new_row>=m||new_col<0||new_col>=n||grid[new_row][new_col] != INF){
continue;
                }
                grid[new_row][new_col] = grid[row][col] + 1;
                q.push({new_row,new_col});
            }
        }
    }
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
//for a tree remember if there are 5 nodes then the edges will be always n-1
if(edges.size()!=n-1){
return false;
}

//building up the adjacncy list for each nodev
vector<vector<int>>adj(n);
for(auto i:edges){
    int first=i[0];
    int second=i[1];
    adj[first].push_back(second);
    adj[second].push_back(first);
}
// Condition 2: The graph must be fully connected.
        // We use BFS starting from node 0 to count how many nodes we can reach.
        queue<int>q;
        vector<bool>visited(n,false);
        int visitedCount=0;
        q.push(0);
        visited[0] = true;
        visitedCount++;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int i : adj[curr]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                    visitedCount++;
                }
            }
        }//basically this is for unconnected bfs se i am just checking jha jha me reaach kar sakta hu 
        if(visitedCount==n){
            return true;
        }else{
            return false;
        }
    }
};

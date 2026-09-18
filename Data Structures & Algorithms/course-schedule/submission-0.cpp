class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);//this will store the neighbouring nodes of all the nodes
        vector<int>indegree(numCourses,0);//for each node storing the indegree
        for(auto i :prerequisites){
           int first= i[0];
           int second=i[1];
           indegree[first]++;
           adj[second].push_back(first);
        }

        //now starting the bfs
        vector<int>toposort;
        queue<int>q;
        for(int i =0;i<numCourses;i++){
            if(indegree[i]==0){
q.push(i);
            }
        }

        //start the bfs
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            toposort.push_back(curr);
            for(auto i:adj[curr]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
    
    if(toposort.size()==numCourses){
        return true;
    }else{
        return false;
    }}
    
};
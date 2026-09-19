class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto i :edges){
            int first=i[0];
            int second=i[1];
            adj[first].push_back(second);
            adj[second].push_back(first);
        }

        vector<bool>visited(n,false);
        int  components=0;

        for(int i =0;i<n;i++){
            if(!visited[i]){
            components++;
            queue<int>q;
            q.push(i);
            visited[i]=true;
            while(!q.empty())
            {
                int curr=q.front();
                q.pop();
                for(auto c :adj[curr]){
                    if(!visited[c]){
                        visited[c]=true;
                        q.push(c);
                    }
                }
            }        

            }
    }
        return components;}
};

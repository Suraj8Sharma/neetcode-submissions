class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //so first we need the frequencies
        unordered_map<char,int>mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        //i have the frequencies need to make  a maxheap
        priority_queue<pair<int,int>>maxheap;
        for(auto i:mp){
            maxheap.push({i.second,0});
        }
        queue<pair<int,int>>q;
        int time=0;
        //pop the values add to queue to hold the pending one
        while(!maxheap.empty()|| !q.empty()){
            time++;
            if(!maxheap.empty()){
                pair<int,int>top=maxheap.top();
                int freq=top.first-1;
                maxheap.pop();
                if(freq!=0){
                    q.push({freq,time+n});
                }


            }
            if(!q.empty() && q.front().second==time){
                maxheap.push(q.front());
                q.pop();
            }
        }
    return time;}
};

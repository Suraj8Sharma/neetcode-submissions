class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
     //we need to calculate frequencies and kisko karna chaiey for minimum the maximum frequency one 
     unordered_map<char,int>mp;
     for(int i =0;i<tasks.size();i++){
        mp[tasks[i]]++;
     }  
     //now we wanted to have the top most first so we need to make a maxheap
     priority_queue<int>max_heap;
     for(auto i:mp){
        max_heap.push(i.second);
     }
    queue<pair<int,int>>q;
     //so now at the top i have the most frequent 
     int time=0;
     while(!max_heap.empty() || !q.empty()){
        time++;
        if(!max_heap.empty()){
            int top=max_heap.top();
            int freq=top-1;
            max_heap.pop();
            if(freq!=0){
                q.push({freq,time+n});
            }
        }
         if(!q.empty() && time==q.front().second){
                max_heap.push(q.front().first);
                q.pop();
            }


     }
   return time; }
};
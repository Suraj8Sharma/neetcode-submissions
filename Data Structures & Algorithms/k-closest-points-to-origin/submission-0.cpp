class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>max_heap;
        for(int  i  =0;i<points.size();i++){
            int first=points[i][0];
            int second=points[i][1];
            int distance=first*first+second*second;
            max_heap.push({distance,{first,second}});
            if(max_heap.size()>k){
                max_heap.pop();
            }
        }
        //now pulling the values
        vector<vector<int>>ans;
        while(max_heap.size()!=0){
            int  first=max_heap.top().second.first;
            int  second=max_heap.top().second.second;
            ans.push_back({first,second});
            max_heap.pop();
        }
    return ans;}
};

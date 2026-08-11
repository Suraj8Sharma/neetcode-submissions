class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
   unordered_map<int,int>mp;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        //make  a maxheap
        priority_queue<pair<int,int>>q;
        for(auto i :mp){
            q.push({i.second,i.first});
        }

        //getting the top -3
        vector<int>result;
        while(!q.empty()&& k>0){
            result.push_back(q.top().second);
            q.pop();
            k--;
        }
    return result;}
};

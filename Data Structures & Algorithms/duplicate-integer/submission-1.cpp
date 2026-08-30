class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
     //duolicate so lets store the count and give the answer from there 
     unordered_map<int,int>count;
     for(int i =0;i<nums.size();i++){
        count[nums[i]]++;
     }   
     //now travel the map and give the answer if you hit a 2 
     for(auto i :count){
        if(i.second>=2){
            return true;
        }

     }
     return false;
    }
};
    
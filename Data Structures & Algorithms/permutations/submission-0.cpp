class Solution {
public:
    void backtrack(vector<int>&current,vector<vector<int>>&result,vector<int>&nums,vector<bool>&visited){
       if(current.size()==nums.size()){
        result.push_back(current);
        return ;
       } 
       for(int i =0;i<nums.size();i++){
        if(!visited[i]){
            visited[i]=true;
            current.push_back(nums[i]);
            backtrack(current,result,nums,visited);
            current.pop_back();
            visited[i]=false;
        }
       }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>current;
        vector<vector<int>>result;
        vector<bool>visited(nums.size(),false);
    backtrack(current,result,nums,visited);
    return result;
    }
};
class Solution {
public:
    void backtrack(int index,vector<int>&current,vector<vector<int>>&result,vector<int>&candidates,int target){

        if(target==0){
            result.push_back(current);
        }
        for(int i =index;i<candidates.size();i++){
            if(candidates[i]<=target){
                current.push_back(candidates[i]);
                backtrack(i,current,result,candidates,target-candidates[i]);
                current.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>current;
        vector<vector<int>>result;
        backtrack(0,current,result,nums,target);
        return result;
    }
};

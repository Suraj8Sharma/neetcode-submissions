class Solution {
public:
    void backtrack(int index,vector<int>&current,vector<vector<int>>&result,vector<int>&nums,int target){
        if(target==0){
            result.push_back(current);
        }
        for(int i =index;i<nums.size();i++){
            if(nums[i]<=target){
                current.push_back(nums[i]);
                backtrack(i,current,result,nums,target-nums[i]);
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

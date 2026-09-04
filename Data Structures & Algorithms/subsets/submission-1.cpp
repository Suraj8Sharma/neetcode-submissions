class Solution {
public:
    void backtrack(int index,vector<int>&current,vector<vector<int>>&result,vector<int>&nums){
        result.push_back(current);
        for(int i =index;i<nums.size();i++){
            current.push_back(nums[i]);
            backtrack(i+1,current,result,nums);
            current.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int>current;
      vector<vector<int>>result;
      backtrack(0,current,result,nums);
      return result;  
    }
};

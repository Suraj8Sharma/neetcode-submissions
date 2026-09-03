class Solution {
public:
    void  backtrack(int  index,vector<int>&current,vector<vector<int>>&result,vector<int>&nums){
        result.push_back(current);
        for(int i =index;i<nums.size();i++){
            current.push_back(nums[i]);
            backtrack(i+1,current,result,nums);//remmebrr if used indexhere it will be reududantt calls 
            current.pop_back();
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        //here we make the structure for storing our data 
        vector<int> current;
        vector<vector<int>>result;
        backtrack(0,current,result,nums);
        return result;
    }
};
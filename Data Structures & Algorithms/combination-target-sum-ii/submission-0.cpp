class Solution {
public:
void backtrack(int index,vector<int>&current,vector<vector<int>> &result,vector<int>&candidates,int target){
    if(target==0){
        result.push_back(current);
        return ;
    }
    for(int i =index;i<candidates.size();i++){
        if(i>index && candidates[i]==candidates[i-1]){
            continue;

            }
            if(candidates[i]<=target){
            current.push_back(candidates[i]);
            backtrack(i+1,current,result,candidates,target-candidates[i]);
            current.pop_back();
        }
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
     vector<int>current;
     vector<vector<int>>result;
     backtrack(0,current,result,candidates,target);
     return result;

    }
};
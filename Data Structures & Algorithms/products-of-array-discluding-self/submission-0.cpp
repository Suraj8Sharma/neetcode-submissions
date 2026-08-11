class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    //to do in o(n) we need to make an suffix product and one prefix product
       vector<int>prefix_product(nums.size(),1);
       vector<int>suffix_product(nums.size(),1);
       for(int i =1;i<nums.size();i++){
        prefix_product[i]=prefix_product[i-1]*nums[i-1];
       }
       for(int i=nums.size()-2;i>=0;i--){
        suffix_product[i]=suffix_product[i+1]*nums[i+1];
       }
       vector<int>ans;
       for(int i =0;i<nums.size();i++){
        ans.push_back(prefix_product[i]*suffix_product[i]);
       }
    return ans;}
};

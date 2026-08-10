class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
       unordered_map<string,vector<string>>freq;
        for(int i =0;i<strs.size();i++){
            string original=strs[i];
            string newsorted=original;
            sort(newsorted.begin(),newsorted.end());
            freq[newsorted].push_back(original);
        
        }
        //now needed to return the vector of strings back so lets travel in thte map 
        vector<vector<string>>ans;
        for(auto i :freq){
            ans.push_back(i.second);
        }
    return ans;}
};

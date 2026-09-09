class Solution {
public:
void backtrack(int index,string &current,string &digits,unordered_map<char,string>&mp,vector<string>&ans){

    if(current.size()==digits.size()){
        ans.push_back(current);
        return ;
    }
    char key=digits[index];
    string letters=mp[key];
    for(int i =0;i<letters.size();i++){
        current.push_back(letters[i]);
        backtrack(index+1,current,digits,mp,ans);
        current.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
         unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> ans;
        string current = "";
        backtrack(0,current, digits, mp, ans);
        return ans;
    }
};

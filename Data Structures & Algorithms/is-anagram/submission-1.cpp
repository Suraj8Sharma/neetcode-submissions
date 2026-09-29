class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size()<s.size()){
            return false;
        }
        vector<int>count(26,0);
        for(int i =0;i<s.size();i++){
            count[s[i]-'a']++;
        }
        //now decrease the count with t string 
        for(int i =0;i<t.size();i++){
            if(count[t[i]-'a']==0){
                return false;
            }
            count[t[i]-'a']--;
        }
    return true;
    }
};

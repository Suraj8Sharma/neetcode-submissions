class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string="";
        for(int i =0;i<strs.size();i++){
            encoded_string += to_string(strs[i].size()) + "#" + strs[i];
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string>decoded;
        int i =0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int length=stoi(s.substr(i,j-i));
            decoded.push_back(s.substr(j+1,length));
            i=j+1+length;
        }
   return decoded; }
};

class Solution {
public:
bool contains(vector<int>freq_t,vector<int>freq_s){
    for(int i =0;i<freq_s.size();i++){
        if(freq_t[i]>freq_s[i]){
            return false;
        }
    }
return true;}
    string minWindow(string s, string t) {
      if(s.size()<t.size()){
            return "";
        }
        //making a character map for t 
        vector<int>freq_t(128,0);
        vector<int>freq_s(128,0);
        for(char c:t){
            freq_t[c]++;
        }
        int left=0;
        int min_window=INT_MAX;
        int minstart=0;
        for(int right=0;right<s.size();right++){
            freq_s[s[right]]++;
            while(contains(freq_t,freq_s)){
                if(right-left+1<min_window){
                    min_window=right-left+1;
                    minstart=left;
                    
                }
                freq_s[s[left]]--;
                left++;
            }
        }
  if(min_window==INT_MAX){
    return "";

  } else{
    return s.substr(minstart,min_window);
  } 
    }
};

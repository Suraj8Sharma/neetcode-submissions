class Solution {
public:
    bool checkInclusion(string s1, string s2) {
   if(s2.size()<s1.size()){
        return false;
     }
     // it is a fixed size sliding window the size of window is equal to size of s1 
     vector<int>freq_s1(26,0);
     vector<int>freq_s2(26,0);
     for(int i =0;i<s1.size();i++){
        freq_s1[s1[i]-'a']++;
        freq_s2[s2[i]-'a']++;
     }
     if(freq_s1==freq_s2){
        return true;
     }
     //if false need to move furthur in the windows
     for(int i=s1.size();i<s2.size();i++){
        freq_s2[s2[i]-'a']++;
        //moving out from the window 
        freq_s2[s2[i-s1.size()]-'a']--;
        if(freq_s1==freq_s2){
            return true;
        }
     }

    return false;}
};

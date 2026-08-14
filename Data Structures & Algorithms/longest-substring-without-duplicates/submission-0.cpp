class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(128,0);
        int left=0;
        int length=0;
        for(int i =0;i<s.size();i++){
            while(freq[s[i]]>0){
                freq[s[left]]--;
                left++;
            }
            freq[s[i]]++;
    length=max(length,i-left+1);
        }
  return length;  }
};

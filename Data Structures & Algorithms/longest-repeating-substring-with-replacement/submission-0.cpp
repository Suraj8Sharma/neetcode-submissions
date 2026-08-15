class Solution {
public:
    int characterReplacement(string s, int k) {
       // this is of variable size slidign window
        vector<int>freq(26,0);
        int maxfrequency=0;//in the window what is the maximum frequency of character 
        int left=0;
        int longest_substr=0;
        for(int right=0;right<s.size();right++){
            freq[s[right]-'A']++;
            //finding the most frequent element within the window 
            maxfrequency=max(maxfrequency,freq[s[right]-'A']);
            //now see if i know the window size - maxfrequency will give me the no of changes required to do 

            while(right-left+1-maxfrequency>k){
                freq[s[left]-'A']--;
                left++;
                //now i need to find the maxfrequency again
                maxfrequency=0;
                for(int i =0;i<26;i++){
                    maxfrequency=max(maxfrequency,freq[i]);
                }
            }
            longest_substr=max(right-left+1,longest_substr);
        }
    return longest_substr;}
};

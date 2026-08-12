class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
          int maxcount=0;
        unordered_set<int>s(nums.begin(),nums.end());
        //i  will travel in the hash set
        for(auto i :s){
            if(s.count(i-1)){
                continue;
            }
            int count=1;
            while(s.count(i+1)){
                count++;
                i++;
            }
        
        maxcount=max(maxcount,count);}

    return maxcount;}
};

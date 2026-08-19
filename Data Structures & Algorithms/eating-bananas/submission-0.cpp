class Solution {
public:
    long long  eathours(vector<int>&piles,long long  mid){
        long long  hours=0;
        for(int i=0;i<piles.size();i++){
            hours+=piles[i]/mid;
            //for the remining pile
            if(piles[i]%mid!=0){
            hours++;
        }}
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long  start=1;
        long long  end=*max_element(piles.begin(),piles.end());
        long long  mid;
        long long  ans;
        while(start<=end){
            mid=start+(end-start)/2;
            long long  hours=eathours(piles,mid);
            if(hours<=h){
                //this means i can eat at the mid speed;
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
    }
        return ans;}
};

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;
        int maxamount=0;
        while(i<j){
            int water_amount=min(heights[i],heights[j])*(j-i);
            maxamount=max(maxamount,water_amount);
            //now incrementing and tthe decrementing logic
            if(heights[i]<heights[j]){
                i++;
            }else{
                j--;
            }
        }
    return  maxamount;}
};

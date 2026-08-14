class Solution {
public:
    int trap(vector<int>& height) {
int left=0;
int right=height.size()-1;
int leftmax=0;
int rightmax=0;
int trapped_water=0;
//we are always collecting that ek block ke upar kitna pani we can store 
while(left<right){
leftmax=max(leftmax,height[left]);
rightmax=max(rightmax,height[right]);
int limit=min(leftmax,rightmax);
if(leftmax<rightmax){
trapped_water+=limit-height[left];
left++;
}else{
    trapped_water+=limit-height[right];
    right--;
}
}
    return trapped_water;}
};

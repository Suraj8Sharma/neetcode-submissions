class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     //now i have to merge the two then give the answer
        for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        //sort the arrays
        sort(nums1.begin(),nums1.end());
        if(nums1.size()%2==1){
            return nums1[(nums1.size())/2];
        }else{
            return (double)(nums1[nums1.size()/2]+nums1[(nums1.size()-1)/2])/2;
        }
   return -1; }
};

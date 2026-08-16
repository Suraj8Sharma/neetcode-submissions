class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>result;
        deque<int>dq;
        for(int right=0;right<nums.size();right++){
            //storing the indexes so front pe leaving index ajayega 
            if(!dq.empty() && dq.front()==right-k){
                dq.pop_front();
            }
            //if value ane wale badi ha then no poitn of stroing the values in teh queue which are smaller 
            while(!dq.empty() && nums[dq.back()]<=nums[right]){
                dq.pop_back();
            }
            //pushig the values to the end because it can be the maxium for thecoming windows
            dq.push_back(right);
            //writing the resulr
            if(right>=k-1){
                result.push_back(nums[dq.front()]);
            }
        }
    return result;}
};

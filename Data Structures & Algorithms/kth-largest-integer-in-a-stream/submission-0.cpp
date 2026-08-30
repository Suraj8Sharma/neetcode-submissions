class KthLargest {
public:
int K;
priority_queue<int,vector<int>,greater<int>>min_heap;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i =0;i<nums.size();i++){
        add(nums[i]);
        }

    }
    
    int add(int val) {
        min_heap.push(val);
        if(min_heap.size()>K){
            min_heap.pop();
        }
    return min_heap.top();}
};

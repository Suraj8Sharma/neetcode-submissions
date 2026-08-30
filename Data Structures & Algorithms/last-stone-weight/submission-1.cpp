class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>max_heap;
        for(int i=0;i<stones.size();i++){
            max_heap.push(stones[i]);
        }

        //now playing the simulation  
        while(max_heap.size()>1){
            int first=max_heap.top();
            max_heap.pop();
            int second=max_heap.top();
            max_heap.pop();
            if(first==second){
                max_heap.push(0);
            }else if(first>second){
                max_heap.push(first-second);
            }
        }
    return max_heap.top();}
};

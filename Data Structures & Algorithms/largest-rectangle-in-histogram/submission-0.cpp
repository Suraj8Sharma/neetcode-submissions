class Solution {
public:
vector<int>pse(vector<int>heights){
    vector<int>ans(heights.size(),-1);
    stack<int>st;//increasing stack
    for(int i =heights.size()-1;i>=0;i--){
        while(!st.empty() && heights[i]<heights[st.top()]){
            int top=st.top();
            st.pop();
            ans[top]=i;
        }
        st.push(i);
    }
    return ans;
}

vector<int>nse(vector<int>heights){
    vector<int>ans(heights.size(),-1);
    stack<int>st;//increasing stack
    for(int i =0;i<heights.size();i++){
        while(!st.empty() && heights[i]<heights[st.top()]){
            int top=st.top();
            st.pop();
            ans[top]=i;
        }
        st.push(i);
    }
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        vector<int>pse_e=pse(heights);
        vector<int>nse_e=nse(heights);
int maxarea=0;
int previous;
int next;

for(int i=0;i<heights.size();i++){
    previous=pse_e[i];
    next=nse_e[i];
    if(next==-1){
        next=heights.size();
    }
    maxarea=max(maxarea,(next-previous-1)*heights[i]);
}
return maxarea; }
};

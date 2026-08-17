class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack <double>st;
        int n=position.size();
        vector<pair<int,int>>cars(n);
        for(int i =0;i<n;i++){
            cars[i]={position[i],speed[i]};
        }

        //sort the neares to the first
        sort(cars.rbegin(),cars.rend());

        for(int i =0;i<n;i++){
            double time =(double)(target-cars[i].first)/cars[i].second;

            if(st.empty()  || time>st.top()){
                st.push(time);
            }
        }
    return st.size();}
};

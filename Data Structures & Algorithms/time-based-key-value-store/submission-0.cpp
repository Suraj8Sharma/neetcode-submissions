class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        string ans;
        if(!mp.contains(key)){
            return "";
        }
        vector<pair<string,int>>& arr=mp[key];
        int left=0;
        int right=arr.size()-1;
        int mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(arr[mid].second==timestamp){
            ans=arr[mid].first;
            return ans;
            }
            else if (arr[mid].second<timestamp){
                ans=arr[mid].first;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        
    return ans;}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
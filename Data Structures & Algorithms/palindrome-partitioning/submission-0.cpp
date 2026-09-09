class Solution {
public:
bool isPalin(string part){
    int left=0;
    int right=part.size()-1;
    while(left<right){
        if(part[left]==part[right]){
            left++;
            right--;
        }else{
            return false;
        }
    
    }
return true;}
void getallparts(string s ,vector<string>&partitions,vector<vector<string>>&result){
    if(s.size()==0){
        result.push_back(partitions);
        return;
    }
    for(int i =0;i<s.size();i++){
        string part=s.substr(0,i+1);//i+1 baasically tells the length
        if(isPalin(part)){
            partitions.push_back(part);
            getallparts(s.substr(i+1),partitions,result);
            partitions.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<string>partitions;
        vector<vector<string>>ans;
        getallparts(s,partitions,ans);
        return ans;
    }
};
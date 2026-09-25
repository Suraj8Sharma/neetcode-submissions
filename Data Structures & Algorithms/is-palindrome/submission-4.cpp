class Solution {
public:
    bool isPalindrome(string s) {
        string forward_string="";
       for(int i =0;i<s.size();i++){
        if(isalnum(s[i])){
            forward_string+=tolower(s[i]);
        }
       } 

    int i =0;
    int j=forward_string.size()-1;
    while(i<j){
        if(forward_string[i]==forward_string[j]){
            i++;
            j--;
        }else{
            return false;
        }
    }
return true;
    }
};

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<int>st;
        int first;
        int second;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                second=st.top();
                st.pop();
                first=st.top();
                st.pop();
                
                st.push(first + second);
            }else if(tokens[i]=="-"){
                second=st.top();
                st.pop();
                first=st.top();
                st.pop();
                st.push(first-second);
            }
            else if(tokens[i]=="*"){
                second=st.top();
                st.pop();
                first=st.top();
                st.pop();
                st.push(first*second);
            }
              else if(tokens[i]=="/"){
                second=st.top();
                st.pop();
                first=st.top();
                st.pop();
                st.push(first/second);
            }else{
                st.push(stoi(tokens[i]));
            }
        }
 return st.top();   }
};

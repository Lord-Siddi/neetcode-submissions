class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string curr="";

        for(int i=0;i<=path.size();i++){
            if(i==path.size()||path[i]=='/'){
                if(curr==""||curr=="."){}
                else if(curr==".."){
                    if(!st.empty())st.pop();
                }else{
                    st.push(curr);
                }
                curr="";
            }else{
                curr+=path[i];
            }
        }
        vector<string>dirs;

        while(!st.empty()){
            dirs.push_back(st.top());
            st.pop();
        }
        reverse(dirs.begin(),dirs.end());
        string res;
        for(auto dir:dirs){
            res+="/";
            res+=dir;
        }
        return res.empty()?"/":res;
    }
};
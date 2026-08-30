class Solution {
public:
    string simplifyPath(string path) {

        vector<string > s;

        int n=path.size();
        int i=0;
        while(i<n)
        {
            while(i<n && path[i]=='/')i++;
            string t="";
            while(i<n && path[i]!='/')
            {
                t+=path[i];i++;
            }
            if(t=="" || t==".")continue;
            else if(t=="..")
            {
                if(!s.empty()) s.pop_back();
                
            }
            else
            {
                s.push_back(t);
            }


        }

        string ans="";
        for(string x: s)
        {
            ans+="/"+x;
        }

        if(ans=="")return "/";
        else return ans;
        
    }
};
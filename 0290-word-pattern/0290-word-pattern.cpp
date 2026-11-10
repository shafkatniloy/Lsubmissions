class Solution {
public:
    bool wordPattern(string pattern, string s) {
       string mp[26];
        vector<string> x;
        string temp="";
        for(int i=0;i<s.size();i++)
        {
            

            if(s[i]==' ' ){
                x.push_back(temp);
                temp="";
            }
            else
            {
                temp+=s[i];
            }
        }
        x.push_back(temp);
        if(pattern.size()!=x.size())return false;
unordered_map<string, char> used;
        for(int i=0;i<x.size();i++)
        {
           if(mp[pattern[i]-'a']=="")
           {
            if(used.count(x[i])) return false;
            mp[pattern[i]-'a']=x[i];
            used[x[i]]=pattern[i];

           }
           else
           {
            if(mp[pattern[i]-'a']!=x[i]) return false;
           }
            
        }
        return true;

    }

};
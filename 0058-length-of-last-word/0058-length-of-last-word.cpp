class Solution {
public:
    int lengthOfLastWord(string s) {
        int c=0;
        int ans=0;
        for(char x:s)
        {
            if(x==' '){ans=( c!=0 ? c:ans );c=0;}
            else c++;
        }
        ans=( c!=0 ? c:ans );
        return ans;
    }
};
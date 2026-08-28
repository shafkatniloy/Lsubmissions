class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int>s (nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;

        for(auto it=s.begin(); it!=s.end(); it++)
        {

            if(s.find(*it-1) == s.end() )
            {
                int l=1;
                int st=*it+1;
                while(s.find(st)!=s.end())
                {
                    l++;st++;
                }
                ans=max(l,ans);
            } 
        }


        return ans;
        
    }
};
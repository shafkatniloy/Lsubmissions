class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        bool t=false;
        if(nums.size()==0) return ans;
        for(int i=0;i<nums.size()-1;i++)
        {
            int st=nums[i];
            while( i<nums.size()-1 && nums[i+1]==nums[i]+1)i++;

            string x;
            if(st!=nums[i])x=to_string(st)+"->"+to_string(nums[i]);
            else x=to_string(st);

            ans.push_back(x);

            if(i==nums.size()-1)t=true;
            
            

            
        }
        if(!t) {
            string x=to_string(nums[nums.size()-1]);
            ans.push_back(x);
        }

        return ans;


    }
};
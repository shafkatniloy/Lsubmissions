class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;
        
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++)
        {
            int curst=intervals[i][0];
            int curend=intervals[i][1];
            
            if(ans.empty() || curst > ans.back()[1] ) ans.push_back({curst,curend});
            else
            {
                ans.back()[1]=max(ans.back()[1],curend);
            }

            
            
        }
        return ans;
    }
};
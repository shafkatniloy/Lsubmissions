class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        vector<int> a;
        for(int i=0;i<m;i++)
        {
            a.push_back(nums1[i]);
        }
        for(int i=0;i<n;i++)
        {
            a.push_back(nums2[i]);
        }

        sort(a.begin(),a.end());
        nums1=a;
        //return nums1;
        
    }
};
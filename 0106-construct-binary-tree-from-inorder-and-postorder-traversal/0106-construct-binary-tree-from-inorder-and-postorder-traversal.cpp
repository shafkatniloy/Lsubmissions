/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
public:
    unordered_map<int,int> inind;
    int postind;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++)
        {
            inind[inorder[i]]=i;
            postind = postorder.size()-1;
            
        }
        return build(postorder,0,inorder.size()-1);

    }
    TreeNode* build(vector<int>& postorder, int st, int en)
    {
        if(st>en) return nullptr;
        int rootval = postorder[postind--];
        TreeNode* root =new TreeNode(rootval);
        int mid = inind[rootval];

        root->right = build(postorder , mid+1 , en);
        root->left = build(postorder , st, mid-1);
        return root;

    }
};
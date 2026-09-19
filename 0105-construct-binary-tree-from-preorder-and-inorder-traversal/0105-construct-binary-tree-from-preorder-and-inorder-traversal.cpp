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
int preind=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
        {
            inind[inorder[i]]=i;
        }
        return build(preorder , 0,inorder.size()-1);
    }

    TreeNode* build(vector<int> &preorder , int instart,int  inend)
    {
        if(instart > inend )return nullptr;
        int rootVal = preorder[preind++];
        TreeNode* root= new TreeNode(rootVal);
        int mid = inind[rootVal];

        root->left = build(preorder ,instart, mid-1);
        root->right = build(preorder, mid+1, inend);

        return root;
    }
};
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
TreeNode* invertTree(TreeNode* root) {
        
        if(root == nullptr )return root;
        swap(root->left , root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;

    }
bool isSameTree(TreeNode* p, TreeNode* q) {

        if(p==nullptr && q!=nullptr)
        {
            return false;
        }
        else if(q==nullptr && p!=nullptr) return false;

        if(p==nullptr && q==nullptr) 
        {
            return true;
        }
        


        if(p->val != q->val)
        {
            return false;
        }
        
        bool lc=isSameTree(p->left , q->left);
        bool rc=isSameTree(p->right , q->right);
        return lc&rc ;
    }

    bool isSymmetric(TreeNode* root) {

        if(root==nullptr) return true;
        if(root->left== nullptr && root->right==nullptr ) return true;
        if(root->left!= nullptr && root->right!=nullptr ){
            invertTree(root->right);
            return isSameTree(root->left,root->right);
        }
        
        return false;

        
    }
};
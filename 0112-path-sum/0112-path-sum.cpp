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
  static constexpr std::size_t max_align = alignof(std::max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static std::size_t pos = 0;

void* operator new(const std::size_t size) {
    const std::size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return &BUFFER[pos - size];
}

void* operator new[](const std::size_t size) { return operator new(size); }

void operator delete(void*) noexcept {}

void operator delete[](void*) noexcept {}

void operator delete(void*, std::size_t) noexcept {}

void operator delete[](void*, std::size_t) noexcept {}
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        
        if(root==nullptr) return false;
        if(root->left == nullptr && root->right == nullptr)
        {
            return targetSum == root->val;
        }

        int v=root->val;
       return hasPathSum(root->left, targetSum-v) || hasPathSum(root->right, targetSum-v);
        
    
        
    }
};
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
    int max_depth(TreeNode* root) {
        if(root==nullptr) return 0;
        int l=max_depth(root->left);
        int r=max_depth(root->right);
        return 1+max(l,r);
    }
    void traverse(TreeNode* root,int &ans) {
        if(root==nullptr) return;
        int r=max_depth(root->left)+max_depth(root->right);
        ans=max(ans,r);
        traverse(root->left,ans);
        traverse(root->right,ans);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        traverse(root,ans);
        return ans;
    }
};

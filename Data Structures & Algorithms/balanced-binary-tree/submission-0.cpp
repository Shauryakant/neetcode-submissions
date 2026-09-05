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
    int max_depth(TreeNode* root,bool &f) {
        if(root==nullptr) return 0;
        int l=max_depth(root->left,f);
        int r=max_depth(root->right,f);
        if(abs(l-r)>1) f=false;
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        bool f=true;
        max_depth(root,f);
        return f;
    }
};

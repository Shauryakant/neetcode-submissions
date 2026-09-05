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
    void traverse(TreeNode* root,int val, int &ans) {
        if(root==nullptr) return;
        ans=max(ans,val+1);
        val++;
        traverse(root->left,val,ans);
        traverse(root->right,val,ans);
    }
    int maxDepth(TreeNode* root) {
        int ans=0;
        traverse(root,0,ans);
        return ans;
    }
};

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
    void traverse(TreeNode* root) {
        if(root==nullptr) return ;
        if(root->left==nullptr) {
            root->left=root->right;
            root->right=nullptr;
        }
        else if(root->right==nullptr) {root->right=root->left;
        root->left=nullptr;
        
        }
        else {
            swap(root->left,root->right);
        }
        traverse (root->right);
        traverse(root->left);
    }
    TreeNode* invertTree(TreeNode* root) {
        
        traverse(root);
        return root;
    }
};

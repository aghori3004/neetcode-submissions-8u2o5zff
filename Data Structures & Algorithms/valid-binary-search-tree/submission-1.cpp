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
    bool isValidNode(TreeNode* root, long long lo, long long hi){
        if(!root) return true;
        if(root->val <= lo || root->val >= hi) return false;
        return isValidNode(root->left, lo, root->val) && isValidNode(root->right, root->val, hi);
    }

    bool isValidBST(TreeNode* root) {
        return(isValidNode(root, LLONG_MIN, LLONG_MAX));
    }
};

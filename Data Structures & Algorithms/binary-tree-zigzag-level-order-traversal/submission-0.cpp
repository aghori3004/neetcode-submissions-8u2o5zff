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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool order = true;
        vector<vector<int>> ans;
        while(!dq.empty()){
            int size = dq.size();
            vector<int> lvl;
            while(size--){
                TreeNode* curr = dq.front();
                dq.pop_front();
                lvl.push_back(curr->val);
                if(curr->left) dq.push_back(curr->left);
                if(curr->right) dq.push_back(curr->right);
            }
            if(!order){
                reverse(lvl.begin(), lvl.end());
            }
            ans.push_back(lvl);
            order = !order;
        }
        return ans;
    }
};
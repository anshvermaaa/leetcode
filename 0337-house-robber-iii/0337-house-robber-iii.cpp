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
    vector<int> f(TreeNode* root){
        if(root==NULL) return {0,0};
        auto left=f(root->left);
        auto right=f(root->right);
        // take
        int take=root->val+left[1]+right[1];
        // not take
        int notTake=max(left[0],left[1])+max(right[0],right[1]);
        return {take,notTake};
    }
    int rob(TreeNode* root) {
        auto ans=f(root);
        return max(ans[0],ans[1]);
    }
};
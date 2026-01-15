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
    int f(TreeNode* root){
        if(root==NULL) return 0;
        int leftSum=f(root->left);
        int rightSum=f(root->right);
        return root->val+max(leftSum>0?leftSum:0,rightSum>0?rightSum:0);
    }
    void computeMaxSum(TreeNode* root,int &maxSum){
        if(root==NULL) return;
        int leftSum=f(root->left);
        int rightSum=f(root->right);
        maxSum=max(maxSum,root->val+(leftSum>0?leftSum:0)+(rightSum>0?rightSum:0));
        computeMaxSum(root->left,maxSum);
        computeMaxSum(root->right,maxSum);
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int maxSum=INT_MIN;
        computeMaxSum(root,maxSum); 
        return maxSum;
    }
};
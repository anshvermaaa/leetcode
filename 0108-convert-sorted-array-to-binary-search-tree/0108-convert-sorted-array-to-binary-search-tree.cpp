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
    TreeNode* f(vector<int>& nums,int i,int j){
        if(i>j) return NULL;
        if(i==j) return new TreeNode(nums[i]);
        int rootIdx=i+(j-i)/2;
        TreeNode* root=new TreeNode(nums[rootIdx]);
        root->left=f(nums,i,rootIdx-1);
        root->right=f(nums,rootIdx+1,j);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        return f(nums,0,nums.size()-1);
    }
};
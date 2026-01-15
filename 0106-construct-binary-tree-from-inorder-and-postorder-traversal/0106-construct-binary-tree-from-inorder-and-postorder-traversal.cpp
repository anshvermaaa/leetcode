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
    TreeNode* f(vector<int>& inorder, vector<int>& postorder,int i1,int j1,int i2,int j2){
        if(i1>j1||i2>j2) return NULL;
        int dist=0;
        int i=i1;
        while(i<=j1&&inorder[i]!=postorder[j2]){
            dist++;
            i++;
        }
        TreeNode* root=new TreeNode(postorder[j2]);
        root->left=f(inorder,postorder,i1,i-1,i2,i2+dist-1);
        root->right=f(inorder,postorder,i+1,j1,i2+dist,j2-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return f(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};
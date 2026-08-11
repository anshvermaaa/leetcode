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
    TreeNode* f(vector<int>& preorder,int i,int j){
        int n=preorder.size();
        if(i>j) return NULL;
        TreeNode* root=new TreeNode(preorder[i]);
        int k=i+1;
        while(k<n&&preorder[k]<preorder[i]) k++;
        root->left=f(preorder,i+1,k-1);
        root->right=f(preorder,k,j);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        return f(preorder,0,n-1);
    }
};
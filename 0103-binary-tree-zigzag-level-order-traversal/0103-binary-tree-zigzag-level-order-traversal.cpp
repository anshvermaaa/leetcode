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
        if(root==NULL) return {};
        vector<vector<int>> ans;
        bool isLToR=false;
        deque<TreeNode*> qu;
        qu.push_back(root);
        while(!qu.empty()){
            int s=qu.size();
            vector<int> nodes;
            if(!isLToR){
                for(int i=0;i<s;i++){
                    auto curr=qu.front();
                    qu.pop_front();
                    nodes.push_back(curr->val);
                    if(curr->left) qu.push_back(curr->left);
                    if(curr->right) qu.push_back(curr->right);
                }
            }else{
                for(int i=0;i<s;i++){
                    auto curr=qu.back();
                    qu.pop_back();
                    nodes.push_back(curr->val);
                    if(curr->right) qu.push_front(curr->right);
                    if(curr->left) qu.push_front(curr->left);
                }
            }
            isLToR=!isLToR;
            ans.push_back(nodes);
        }
        return ans;
    }
};
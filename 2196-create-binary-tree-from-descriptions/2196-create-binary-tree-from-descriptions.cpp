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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> vis;
        for(int i=0;i<descriptions.size();i++){
            int par=descriptions[i][0];
            int child=descriptions[i][1];
            int isLeft=descriptions[i][2];
            if(!mp.count(par)) mp[par]=new TreeNode(par);
            if(!mp.count(child)) mp[child]=new TreeNode(child);
            if(isLeft) mp[par]->left=mp[child];
            else mp[par]->right=mp[child];
            vis.insert(child);
        }
        for(auto it:mp){
            if(!vis.count(it.first)) return mp[it.first];
        }
        return nullptr;
    }
};
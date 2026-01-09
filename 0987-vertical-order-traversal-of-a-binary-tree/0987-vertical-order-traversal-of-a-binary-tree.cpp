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
    void fillNodes(TreeNode* root,vector<vector<int>> &nodes,int idx,int jdx){
        if(root==NULL) return;
        nodes.push_back({idx,jdx,root->val});
        fillNodes(root->left,nodes,idx-1,jdx+1);
        fillNodes(root->right,nodes,idx+1,jdx+1);
    }
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]<b[0]) return true;
        else if(a[0]==b[0]&&a[1]<b[1]) return true;
        else if(a[0]==b[0]&&a[1]==b[1]&&a[2]<b[2]) return true;
        return false;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> nodes; // (idx,value)
        fillNodes(root,nodes,0,0);
        sort(nodes.begin(),nodes.end(),comp);
        vector<vector<int>> ans;
        vector<int> temp;
        int currIdx=INT_MIN;
        for(int i=0;i<nodes.size();i++){
            if(currIdx!=nodes[i][0]){
                if(currIdx!=INT_MIN){
                    ans.push_back(temp);
                    temp.clear();
                }
            }
            temp.push_back(nodes[i][2]);
            currIdx=nodes[i][0];
        }
        if(temp.size()) ans.push_back(temp);
        return ans;
    }
};
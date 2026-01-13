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
    int f(TreeNode* root,vector<int> &subTreeSum){
        if(root==NULL) return 0;
        int temp=root->val+f(root->left,subTreeSum)+f(root->right,subTreeSum);
        subTreeSum.push_back(temp);
        return temp;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
       if(root==NULL) return {};
       vector<int> subTreeSum;
       f(root,subTreeSum);
       priority_queue<pair<int,int>> pq; // freq,val
       unordered_map<int,int> mp; // val,freq
       int bestFreq=0;
       for(int i=0;i<subTreeSum.size();i++){
        mp[subTreeSum[i]]++;
        bestFreq=max(bestFreq,mp[subTreeSum[i]]);
       }
       vector<int> ans;
       for(auto &it:mp){
        if(it.second==bestFreq) ans.push_back(it.first);
       }
       return ans;
    }
};
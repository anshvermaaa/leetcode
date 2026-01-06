/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    void f(TreeNode* root,string &ans){
        if(root==NULL){
            ans+="#####";
            return;
        }
        bool pos=true;
        if(root->val<0) pos=false;
        if(pos) ans+='+';
        else {
            ans+='-';
            root->val=(-root->val);
        }
        string temp=to_string(root->val);
        if(temp.size()<4){
            for(int i=0;i<(4-temp.size());i++){
                ans+="0";
            }
        }
        ans+=temp;
        f(root->left,ans);
        f(root->right,ans);
    }

    TreeNode* buildTree(string &s,int &i){
        if(i>=s.size()) return NULL;
        string temp=s.substr(i,5);
        i+=5;
        if(temp=="#####") return NULL;
        TreeNode* root=new TreeNode(stoi(temp));
        root->left=buildTree(s,i);
        root->right=buildTree(s,i);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        f(root,ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        return buildTree(data,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
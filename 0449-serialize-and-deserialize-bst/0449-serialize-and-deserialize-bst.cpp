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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        queue<TreeNode*> qu;
        string s="";
        s+=to_string(root->val);
        qu.push(root);
        while(!qu.empty()){
            auto curr=qu.front();
            qu.pop();
            if(curr->left==NULL){
                s+=" ";
                s+="n";
            }else {
                qu.push(curr->left);
                s+=" ";
                s+=to_string(curr->left->val);
            }
            if(curr->right==NULL){
                s+=" ";
                s+="n";
            }else {
                qu.push(curr->right);
                s+=" ";
                s+=to_string(curr->right->val);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        vector<TreeNode*> nodes;
        string temp="";
        for(int i=0;i<data.size();i++){
            if(data[i]==' '){
                if(temp=="n") nodes.push_back(NULL);
                else nodes.push_back(new TreeNode(stoi(temp)));
                temp="";
            }
            else temp+=data[i];
        }
        if(temp!="n") nodes.push_back(new TreeNode(stoi(temp)));
        queue<TreeNode*> qu;
        TreeNode* root=nodes[0];
        qu.push(root);
        int i=0;
        int n=nodes.size();
        while(!qu.empty()&&i<n){
            auto curr=qu.front();
            qu.pop();
            if(i+1<n&&nodes[i+1]!=NULL){
                curr->left=nodes[i+1];
                qu.push(nodes[i+1]);
            }
            if(i+2<n&&nodes[i+2]!=NULL){
                curr->right=nodes[i+2];
                qu.push(nodes[i+2]);
            }
            i+=2;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
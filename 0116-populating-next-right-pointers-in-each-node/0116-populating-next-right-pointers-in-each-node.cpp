/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*> qu;
        qu.push(root);
        while(!qu.empty()){
            auto curr=qu.front();
            qu.pop();
            if(curr->left) qu.push(curr->left);
            if(curr->right) qu.push(curr->right);
            if(curr->left&&curr->right) curr->left->next=curr->right;
            if(curr->next&&curr->next->left&&curr->right) curr->right->next=curr->next->left;
        }
        return root;
    }
};
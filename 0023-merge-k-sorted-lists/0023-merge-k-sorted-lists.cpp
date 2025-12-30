/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        typedef pair<int,ListNode*> Node;
        priority_queue<Node,vector<Node>,greater<Node>> pq;
        int n=lists.size();
        for(int i=0;i<n;i++){
            if(lists[i]!=NULL)
                pq.push({lists[i]->val,lists[i]});
        }
        ListNode* newNode=new ListNode(1);
        ListNode* temp=newNode;

        while(pq.size()>0){
            auto node=pq.top();
            pq.pop();
            temp->next=node.second;
            temp=temp->next;
            if(temp->next!=NULL) pq.push({temp->next->val,temp->next});
        }
        return newNode->next;
    }
};
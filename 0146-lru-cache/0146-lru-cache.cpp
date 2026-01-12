class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key,int val){
        this->val=val;
        this->key=key;
        this->next=NULL;
        this->prev=NULL;
    }
};
class LRUCache {
private:
    void insertAtHead(Node* node){
        Node* temp=head->next;
        head->next=node;

        node->prev=head;
        node->next=temp;

        temp->prev=node;
    }
    Node* deleteNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
        return node;
    }
public:
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        Node* node=mp[key];
        deleteNode(node);
        insertAtHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            mp[key]->val=value;
            deleteNode(mp[key]);
            insertAtHead(mp[key]);
            return;
        }
        if(capacity==mp.size()){
            Node* temp=tail->prev;
            deleteNode(temp);
            insertAtHead(temp);
            mp.erase(temp->key);
            temp->val=value;
            temp->key=key;
            mp[key]=temp;
        }else{
            Node* temp=new Node(key,value);
            insertAtHead(temp);
            mp[key]=temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
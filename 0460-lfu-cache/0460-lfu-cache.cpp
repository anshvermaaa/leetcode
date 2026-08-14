struct Node{
    int key,val,counter;
    Node* next;
    Node* prev;
    Node(int key_,int val_){
        key=key_;
        val=val_;
        counter=1;
    }
};
class LL{
public:
    Node* head;
    Node* tail;
    int s;
    LL(){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        s=0;
    }
    ~LL() {
        delete head;
        delete tail;
    }
    void insertAtHead(Node* node){
        node->next=head->next;
        head->next->prev=node;
        node->prev=head;
        head->next=node;
        s++;
    }
    void deleteLastNode(unordered_map<int,Node*> &mp){
        Node* node=tail->prev;
        deleteNode(node);
        mp.erase(node->key);
        delete node;
    }
    void deleteNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
        s--;
    }
};
void initializeIfNotPresent(map<int,LL*> &freq,int f){
    if(!freq.count(f)){
        freq[f]=new LL();
    }
}
void deleteIfSizeZero(map<int,LL*> &mp,LL* ll,int f){
    if(ll->s==0){
        mp.erase(f);
        delete ll;
    }
}
class LFUCache {
    unordered_map<int,Node*> mp;
    map<int,LL*> freq;
    int cap;
    int s;
public:
    LFUCache(int capacity) {
        cap=capacity;
        s=0;
    }
    
    int get(int key) {
        if(!mp.count(key)||cap == 0) return -1;
        Node* node=mp[key];
        freq[node->counter]->deleteNode(node);
        deleteIfSizeZero(freq,freq[node->counter],node->counter);
        node->counter++;
        initializeIfNotPresent(freq,node->counter);
        freq[node->counter]->insertAtHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(cap==0) return;
        if(mp.count(key)){
            Node* node=mp[key];
            node->val=value;

            freq[node->counter]->deleteNode(node);
            deleteIfSizeZero(freq, freq[node->counter], node->counter);

            node->counter++;
            initializeIfNotPresent(freq,node->counter);
            freq[node->counter]->insertAtHead(node);
        }else{
            if(cap==s){
                LL* lowestFreqList=freq.begin()->second;
                int f=freq.begin()->first;
                lowestFreqList->deleteLastNode(mp);
                deleteIfSizeZero(freq,lowestFreqList,f);
                s--;
            }
            mp[key]=new Node(key,value);
            Node* node=mp[key];
            initializeIfNotPresent(freq,1);
            freq[1]->insertAtHead(node);
            s++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
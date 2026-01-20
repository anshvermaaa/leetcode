struct Node{
    int val;
    Node* next;
    Node(int _val){
        val=_val;
        next=NULL;
    }
};
class MyLinkedList {
    Node* head;
    int size=0;
public:
    MyLinkedList() {
        head=NULL;
    }
    
    int get(int index) {
        if(index<0||index>=size) return -1;
        Node* temp=head;
        for(int i=0;i<index;i++) temp=temp->next;
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* temp=new Node(val);
        if(head==NULL){
            head=temp;
            size++;
            return;
        }
        temp->next=head;
        head=temp;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            size++;
            return;
        }
        Node* temp=head;
        while(temp->next) temp=temp->next;
        temp->next=newNode; 
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size||index<0) return;
        if(index==size){
            addAtTail(val);
            return;
        }
        if(index==0){
            addAtHead(val);
            return;
        }
        Node* temp=head;
        for(int i=0;i<index-1;i++) temp=temp->next;
        Node* newNode=new Node(val);
        newNode->next=temp->next;
        temp->next=newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=size||index<0) return;
        if(index==0){
            head=head->next;
            size--;
            return;
        }
        Node* temp=head;
        for(int i=0;i<index-1;i++) temp=temp->next;
        temp->next=temp->next->next;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
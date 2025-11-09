class MyStack {
public:
    queue<int> qu;
    MyStack() {
        
    }
    
    void push(int x) {
       int s=qu.size();
       qu.push(x);
       for(int i=0;i<s;i++){
        qu.push(qu.front());
        qu.pop();
       } 
    }
    
    int pop() {
        if(qu.size()==0) return -1;
        int val=qu.front();
        qu.pop();
        return val;
    }
    
    int top() {
        if(qu.size()==0) return -1;
        return qu.front();
    }
    
    bool empty() {
        return qu.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
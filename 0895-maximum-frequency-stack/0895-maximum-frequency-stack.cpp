class FreqStack {
    typedef pair<int,pair<int,int>> pp; // {freq,{closestWeight,element}}
    priority_queue<pp> pq; // priority_queue
    unordered_map<int,int> freq; // {val->freq}
    int closestWeight;
public:
    FreqStack() {
        closestWeight=0;
    }
    
    void push(int val) {
        freq[val]++;
        pq.push({freq[val],{closestWeight,val}});
        closestWeight++;
    }
    
    int pop() {
        int el=pq.top().second.second;
        pq.pop();
        freq[el]--;
        if(freq[el]==0) freq.erase(el);
        return el;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
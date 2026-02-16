
class LFUCache {
private:
    int capacity;
    unordered_map<int,list<vector<int>>::iterator> mp;
    map<int,list<vector<int>>> freq; // list<[key,val,freq]>
public:
    LFUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        auto node=mp[key];
        int value=(*node)[1];
        int freqOfNode=(*node)[2];
        freq[freqOfNode].erase(node);
        if(freq[freqOfNode].size()==0) freq.erase(freqOfNode);
        freq[freqOfNode+1].push_front({key,value,freqOfNode+1});
        mp[key]=freq[freqOfNode+1].begin();
        return value;
    }
    
    void put(int key, int value) {
        if(!mp.count(key)){
            if(mp.size()==capacity){
                int lfuListKey=freq.begin()->first;
                mp.erase(freq[lfuListKey].back()[0]);
                freq[lfuListKey].pop_back();
                if(freq[lfuListKey].size()==0) freq.erase(lfuListKey);
            }
            freq[1].push_front({key,value,1});
            mp[key]=freq[1].begin();
        }
        else{
            auto node=mp[key];
            int freqOfNode=(*node)[2];
            freq[freqOfNode].erase(node);
            if(freq[freqOfNode].size()==0) freq.erase(freqOfNode);
            freq[freqOfNode+1].push_front({key,value,freqOfNode+1});
            mp[key]=freq[freqOfNode+1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
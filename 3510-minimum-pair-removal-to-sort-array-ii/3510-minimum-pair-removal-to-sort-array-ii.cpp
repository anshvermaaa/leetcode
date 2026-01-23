class Solution {
public:
    typedef long long ll;
    typedef pair<long long,int> p;
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        vector<ll> a(n);
        for(int i=0;i<n;i++) a[i]=nums[i];
        set<p> s;
        vector<int> next(n);
        vector<int> prev(n);
        for(int i=0;i<n;i++){
            next[i]=i+1;
            prev[i]=i-1;
        }
        int ans=0;
        int cnt=0; // count of bad pairs
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) cnt++;
            s.insert({nums[i]+nums[i+1],i});
        }
        while(cnt>0){
            int currIdx=s.begin()->second;
            int nextIdx=next[currIdx];
            while (true) {
        auto it = s.begin();
        currIdx = it->second;
        nextIdx = next[currIdx];

        // stale: no right neighbor
        if (nextIdx >= n) {
            s.erase(it);
            continue;
        }

        // stale: not actually adjacent anymore in the current list
        if (prev[nextIdx] != currIdx) {
            s.erase(it);
            continue;
        }

        ll expected = a[currIdx] + a[nextIdx];

        // stale: sum changed (currIdx value changed after merges)
        if (it->first != expected) {
            s.erase(it);
            s.insert({expected, currIdx});
            continue;
        }

        // this is the real current minimum pair -> consume it
        s.erase(it);
        break;
    }
            int prevIdx=prev[currIdx];
            int next_nextIdx=next[nextIdx];
            if(a[currIdx]>a[nextIdx]) cnt--;
            if(prevIdx>=0&&nextIdx<n){
                // bad->not bad
                if(a[prevIdx]>a[currIdx]&&a[prevIdx]<=a[currIdx]+a[nextIdx]) cnt--;
                // not bad->bad
                else if(a[prevIdx]<=a[currIdx]&&a[prevIdx]>a[currIdx]+a[nextIdx]) cnt++;
            }

            if(next_nextIdx<n){
                // not bad->bad
                if(a[next_nextIdx]>=a[nextIdx]&&a[next_nextIdx]<a[currIdx]+a[nextIdx]) cnt++;
                // bad->not bad
                else if(a[next_nextIdx]<a[nextIdx]&&a[next_nextIdx]>=a[currIdx]+a[nextIdx]) cnt--;
            }
            // add pairs
            if(prevIdx>=0){
                s.erase({a[prevIdx]+a[currIdx],prevIdx});
                s.insert({a[prevIdx]+a[currIdx]+a[nextIdx],prevIdx});
            }
            if(next_nextIdx<n){
                s.erase({a[next_nextIdx]+a[nextIdx],nextIdx});
                s.insert({a[next_nextIdx]+a[currIdx]+a[nextIdx],currIdx});
                prev[next_nextIdx]=currIdx;
            }
            next[currIdx]=next_nextIdx;
            a[currIdx]+=a[nextIdx];
            ans++;
        }
        return ans;
    }
};
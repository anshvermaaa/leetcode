class Solution {
public:
    typedef long long ll;
    void dijkstra(vector<vector<pair<int,int>>> &graph,unordered_map<int,vector<ll>> &dis,int src){
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
        pq.push({0,src});
        dis[src].resize(graph.size(),1e18);
        dis[src][src]=0;
        while(!pq.empty()){
            auto [dist,node]=pq.top();
            pq.pop();
            for(auto [ne,wt]:graph[node]){
                if(dist+wt<dis[src][ne]){
                    dis[src][ne]=dist+wt;
                    pq.push({dis[src][ne],ne});
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string,int> mp; // string->node
        int n=0;
        for(int i=0;i<original.size();i++){
            if(!mp.count(original[i])){
                mp[original[i]]=n;
                n++;
            }
            if(!mp.count(changed[i])){
                mp[changed[i]]=n;
                n++;
            }
        }
        vector<vector<pair<int,int>>> graph(n,vector<pair<int,int>>());
        for(int i=0;i<changed.size();i++){
            graph[mp[original[i]]].push_back({mp[changed[i]],cost[i]});
        }
        unordered_map<int,vector<ll>> dis;
        for(int i=0;i<original.size();i++){
            if(!dis.count(mp[original[i]])){
                dijkstra(graph,dis,mp[original[i]]);
            }
        }
        vector<ll> dp(source.size()+1,1e18);
        dp[source.size()]=0;
        unordered_set<int> lens;
        for(string s:original){
            lens.insert(s.size());
        }
        for(int i=source.size()-1;i>=0;i--){
            if(source[i]==target[i]){
                dp[i]=dp[i+1];
            }
            // substring checking
            for(int len:lens){
                int j=i+len-1;
                if(j>=source.size()) continue;
                string from=source.substr(i,len);
                string to=target.substr(i,len);
                if(!mp.count(from)||!mp.count(to)) continue;
                ll minDisToTarget=dis[mp[from]].size()>0?dis[mp[from]][mp[to]]:1e18;
                if(minDisToTarget<1e18){
                    dp[i]=min(dp[i],minDisToTarget+dp[j+1]);
                }
            }
        }
        return dp[0]>=1e18?-1:dp[0];
    }
};
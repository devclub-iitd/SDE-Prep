class Solution {
public:
    // Use Dijkstra's Algorithm
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto x : times)
        {
            adj[x[0]].push_back({x[1],x[2]});
        }
        vector<int>dist(n+1,INT_MAX) ;
        dist[k] = 0 ;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq ;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            if(node.first  > dist[node.second])
            {
                continue ;
            }

            for(auto x : adj[node.second])
            {
                int p = x.first;
                int w = x.second ;
                if(dist[node.second] + w < dist[p])
                {
                    dist[p] = dist[node.second] + w ;
                    pq.push({dist[p],p});
                }
            }
        }
        int ans = INT_MIN ;
        for(int i = 1 ; i<=n ; i++)
        {
            if(dist[i] == INT_MAX) {return -1;}
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};
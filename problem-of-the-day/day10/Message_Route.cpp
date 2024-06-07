#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1,vector<ll>());
    for(int i = 1 ; i<=m ; i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    priority_queue<pair<ll,ll> , vector<pair<ll,ll>> , greater<pair<ll,ll>>>pq;

    pq.push({1,0});
    vector<ll>dist(n+1,LLONG_MAX);
    dist[1] = 0;
    vector<ll>parent(n+1,-1);

    while(!pq.empty())
    {
        ll node = pq.top().first;
        ll d = pq.top().second ;
        pq.pop();
        for(auto it : adj[node])
        {
            if(d+1 < dist[it])
            {
                parent[it] = node; 
                dist[it] = d+1;
                pq.push({it,d+1});
            }
        }
    }
    if(dist[n] == LLONG_MAX)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<dist[n]+1<<endl;
    vector<ll>path;
    ll i = n ;
    while(i!=-1)
    {
        path.push_back(i);
        i = parent[i];
    }

    for(auto it = path.rbegin() ; it!=path.rend() ; it++)
    {
        cout<<*it<<" ";
    }

}
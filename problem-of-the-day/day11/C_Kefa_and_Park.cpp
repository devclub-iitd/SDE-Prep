#include <bits/stdc++.h>
using namespace std;


// Solve it using recursive relation
// Let's go down the tree from the root, supporting additional parameter k — the number of vertices in a row met with cats consecutively. If k exceeds m, then leave. Then the answer is the number of leaves, which we were able to reach.
int solve(int src , int m , int currentCat , vector<vector<int>>&adj , vector<int>&hasCat , int par)
{
    if(hasCat[src])
    {
        currentCat--;
        if(currentCat < 0)
        {
            return 0;
        }
    }
    else
    {
        currentCat = m ;
    }

    int ans =  0;
    for(auto x : adj[src])
    {
        if(x!= par)
        {
            ans += solve(x,m,currentCat , adj,hasCat , src) ;
        }
    }

    if(adj[src].size() == 1 && adj[src][0] == par)
    {
        ans++;
    }

    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<int>hasCat(n+1,0);
    for(int i = 1 ; i<=n ; i++) {cin>>hasCat[i];}
    vector<vector<int>>adj(n+1);
    for(int i = 1 ; i<=n-1 ; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout<<solve(1,m,m,adj,hasCat,-1)<<endl;



}
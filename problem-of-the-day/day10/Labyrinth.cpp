#include <bits/stdc++.h>
using namespace std;
#define ll long long




int main()
{
    ll n,m;
    cin>>n>>m;
    vector<string>v(n);
    for(int i = 0 ; i<n ; i++)
    {
        cin>>v[i];
    }
    ll startx,starty,endx,endy;
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(v[i][j] == 'A')
            {
                startx = i;
                starty = j;
            }
            if(v[i][j] == 'B')
            {
                endx = i;
                endy = j;
            }
        }
    }
    vector<ll>dirx = {1,-1,0,0};
    vector<ll>diry = {0,0,1,-1};
    priority_queue<vector<ll> , vector<vector<ll>> , greater<vector<ll>>>pq;
    pq.push({0,startx,starty});

    vector<vector<ll>>dist(n,vector<ll>(m,LLONG_MAX));
    dist[startx][starty] = 0;
    vector<vector<ll>>parent(n,vector<ll>(m,-1));

    while(!pq.empty())
    {
        vector<ll>node = pq.top();
        pq.pop();
        ll d = node[0];
        ll x = node[1];
        ll y = node[2];
        for(int i = 0 ; i<4 ; i++)
        {
            ll newx = x + dirx[i];
            ll newy = y + diry[i];
            if(newx>=0 && newx<n && newy>=0 && newy<m && v[newx][newy] != '#' && d+1 < dist[newx][newy])
            {
                dist[newx][newy] = d+1;
                parent[newx][newy] = i;
                pq.push({d+1,newx,newy});
            }
        }
    }
    if(dist[endx][endy] == LLONG_MAX)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    cout<<dist[endx][endy]<<endl;
    vector<string>ans;
    while(endx!=startx || endy!=starty)
    {
        ll i = parent[endx][endy];
        if(i == 0)
        {
            ans.push_back("D");
            endx--;
        }
        else if(i == 1)
        {
            ans.push_back("U");
            endx++;
        }
        else if(i == 2)
        {
            ans.push_back("R");
            endy--;
        }
        else
        {
            ans.push_back("L");
            endy++;
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto it : ans)
    {
        cout<<it;
    }
}
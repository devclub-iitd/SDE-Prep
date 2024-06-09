# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
# define MOD 1000000007
using namespace std;
 
int n,m;
vector <vector<int>> adList;
vector <bool> visit;
vector<int> p;
	
bool bfs(int start){
    queue <int> q;
    q.push(start);
    visit[start]=true;
	while (!q.empty()){
		int v=q.front();
		q.pop();
		for (int &u:adList[v]){
			if (visit[u]) {
                if (p[u]==p[v]) return false;
                continue;
            }
			visit[u]=true;
			p[u]=(p[v]+1)%2;
			q.push(u);
		}
	}
    return true;
}
int main(){
	fastio;
	cin>>n>>m;
	adList.assign(n,vector<int>());
    visit.assign(n,0);
    p.assign(n,-1);
    int x,y;
	for (int i=0;i<m;++i){
		cin>>x>>y;x--;y--;
		adList[x].push_back(y);
		adList[y].push_back(x);
	}
    for (int start=0;start<n;++start){
        if (visit[start]) continue;
        p[start]=0;
        visit[start]=true;
        if (!bfs(start)){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    for (int i=0;i<n;++i) {
        if (i!=0) cout<<' ';
        cout<<p[i]+1;
    }
    cout<<'\n';
	return 0;
}

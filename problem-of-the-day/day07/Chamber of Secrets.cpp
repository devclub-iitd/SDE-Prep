// Libraries
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <string>
#include <limits.h>
#include <set>
#include <map>
using namespace std;

// Operator overloads
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }


// Macros
#define FAST ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define ll long long
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define vp vector<pair<ll,ll>>
#define vi vector<int>
#define vll vector<ll>
#define vv vector<vector<ll>>
#define el '\n'
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define imax 1e8
#define imin INT_MIN
#define llmax LLONG_MAX
#define llmin LLONG_MIN
#define MAXN 200010
#define ff first
#define ss second
#define py cout<<"YES\n"
#define pn cout<<"NO\n"
#define N 1005

int dx[]{0, 1, 0, -1, 1, 1, -1, -1};
int dy[]{1, 0, -1, 0, 1, -1, -1, 1};
char di[]{'R', 'D', 'L', 'U'};

void FOI(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

struct cell{
    int x , y ;
};

ll n , m ;
char grid[N][N];
int dist[N][N] ;
queue<cell>q;

bool valid( int x , int y ){
    return x >= 0 and x < n and y >= 0 and y < m;
}
void bfs( ){

    while( q.size() ){
        cell cur = q.front() ;
        q.pop() ;
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x , ny = cur.y ;
            while( valid( nx + dx[i] , ny + dy[i] ) and dist[nx+dx[i]][ny+dy[i]] > dist[cur.x][cur.y] + 1 ){
                nx = nx + dx[i] , ny = ny + dy[i] ;
                if( grid[nx][ny] == '.') continue;
                if( dist[nx][ny] > dist[cur.x][cur.y] + 1 ){
                    dist[nx][ny] = dist[cur.x][cur.y] + 1 ;
                    q.push({nx, ny} );
                }
            }
        }
    }
    int mini = imax;
    for (ll i = 0; i < m; ++i) {
        if( grid[0][i] == '#' )
        mini = min( mini , dist[0][i] ) ;
    }
    if( mini == imax ) cout << -1;
    else cout << mini + 1;
}

void solve(){
    cin >> n >> m ;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j] ;
            dist[i][j] = imax;
            if( grid[i][j] == '#' and i == n-1 ){
                q.push({i, j} );
                dist[i][j]= 0;
            }
        }
    }
    bfs( );
}

int main(){
    FAST
    FOI();
    int t = 1 ;
//    cin >> t ;
    while(t--){
        solve();
        cout << ( t ? "\n" : "");
    }
}
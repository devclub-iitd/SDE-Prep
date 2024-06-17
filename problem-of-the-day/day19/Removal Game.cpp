#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include<functional>
/// ordered sets support upperbound lowerbound too
#include <map>
#include <unordered_map>
#define len(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using li =  long long;
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define f first
#define mk make_pair
#define in insert
 
const li INF = 1e9;
const li LINF = INF * INF;
 
// ------------------------------------------***--------------------------------------------------
 
vector<vector<li>>dp;
vector<vector<bool>>vis;
vector<li>a,p;
li sum(int l,int r){
    if(l>r)return 0;
    return p[r] - p[l-1];
}
 
li memo(li i,li j){
    if(i>j)return 0;
    else if(vis[i][j])return dp[i][j];
    vis[i][j] = true;
    li op1 = a[i] + sum(i+1,j) - memo(i+1,j);
    li op2 = a[j] + sum(i,j-1) - memo(i,j-1);
    dp[i][j] = max(op1,op2);
    // cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
    return dp[i][j];
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    li n;cin>>n;
    a = vector<li>(n+1);
    p = vector<li>(n+1);
    rep(i,1,n+1)cin>>a[i];
    rep(i,1,n+1)p[i] = p[i-1] + a[i];
    // for(int i:a)cout<<i<<' ';
    // cout<<'\n';
    // for(int i:p)cout<<i<<' ';
    // cout<<'\n';
    dp = vector<vector<li>>(n+1,vector<li>(n+1,-LINF));
    vis = vector<vector<bool>>(n+1,vector<bool>(n+1,false));
    li ans = memo(1,n);
    cout<<ans<<'\n';
    return 0;
}
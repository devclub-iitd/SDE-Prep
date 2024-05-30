#include<bitset>
#include<vector>
#include <iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<unordered_set>
#include<set>
///ordered sets support upperbound lowerbound too
#include<map>
#include<unordered_map>
using namespace std;
#define int long long
#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;i++)
#define f first
#define mk make_pair
#define in insert  
 
int32_t main(){
    int n,x;cin>>n;
    set<int> s;
    rep(i,0,n){
        cin>>x;
        s.insert(x);
    }
    cout<<s.size()<<'\n';
    return 0;
}

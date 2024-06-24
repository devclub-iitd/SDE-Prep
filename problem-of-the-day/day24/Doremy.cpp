#include <bits/stdc++.h>
using namespace std;
#define forn for(int i=0; i<n; i++)
#define arr(a, n) velo a(n); for(int i=0; i<n; i++){cin >> a[i];}
#define inp(b) ll b; cin >> b;
#define rep(i, j, n) for(int i=j; i<n; i++)
#define cyes cout << "YES" << "\n"
#define cno cout << "NO" << "\n"
#define pb push_back
#define minpq priority_queue<int, vector<int>, greater<int>>
#define pq priority_queue
#define F first
#define S second
#define mx(a) max_element(a.begin(), a.end())
#define mn(a) min_element(a.begin(), a.end())
#define print(a, b) cout << a << " " << b << nl
#define nl "\n"

const int M = 1000000007;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> velo;


int bin_search(velo &a, ll num){
    int n = a.size();
    int hi = n-1, lo = 0, mid, big = -1;
    while (lo <= hi){
        mid = (lo + hi)/2;
        if (a[mid] == num){return mid;}
        else if (a[mid] > num){
            big = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    return big;
}

void print_vec(velo &a){
    for(auto x : a){
        cout << x << " ";}
    cout << "\n";
}

//-----------------------------------------------------------

void solve(){
    ll n, q; cin >> n >> q;
    arr(a, n);
    string ans, s;
    forn{
        ans += '0';
    }
    auto check = [&] (int val){
        s = "";
        ll q1 = q;
        for(int i = 0; i < n; i++){
            if(i < val){
                if(a[i] <= q){
                    s += '1';
                }
                else{
                    s += '0';
                }
            }
            else{
                if(q1 == 0) return false;
                if(a[i] > q1){
                    q1--;
                }
                s += '1';
            }
        }
        return true;
    };
    int lo = 0, hi = n-1;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(check(mid)){
            ans = s;
            hi = mid-1;
        }
        else lo = mid + 1;
    }
    cout << ans << nl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
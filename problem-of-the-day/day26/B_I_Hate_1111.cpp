/*The main idea is that we can split the numbers into the two halves, the big half and small half,
 we can place the bigger half at the odd positions and the smaller half at the even positions.

This works because the smallest big number is larger than the biggest small number.
 Hence, the mean of any two small numbers is smaller than any big number, 
and the mean of any two big numbers is bigger than any small number.*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start);x!=(end);((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

int n;
int arr[55];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin.exceptions(ios::badbit | ios::failbit);
    
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        rep(x, 0, 2 * n) cin >> arr[x];
        
        sort(arr, arr + 2 * n);
        
        rep(x, 0, n) cout << arr[x] << " " << arr[x + n] << " ";
        cout << endl;
    }
}

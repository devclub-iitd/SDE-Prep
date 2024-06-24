    #include <bits/stdc++.h> 
     
    using namespace std;
     
    typedef long long ll;
    #define fi first
    #define se second
    #define vl vector<ll>
    #define all(x) (x).begin(), (x).end()
    #define input(a) for (auto &i : a) cin >> i;
     
     
    void solve(){
    }
    int main()
    {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     ll t;
     cin >> t;
     while(t--) {
        ll n,k;
        cin >> n >>k;
        vl A(n);
        input(A);
     
        ll sum=0;
        for(auto i:A) sum+=i;
        sort(A.begin(), A.end());
        if(sum<=k) cout << 0 << endl;
        else{
            ll ans = sum-k;
            //cout << ans << endl;
            sum-=A[0];
            vl S(n,A[n-1]);
            for(int i=n-2;i>=0;i--){
                S[i] = S[i+1] + A[i];
            }
            for(int i=n-1;i>=1;i--){
                ll low =0, high = 1e9*2;
                while(low<=high){
                    ll mid= (low+high)/2;
                    ll temp = (INT_MAX)/(n-i+1);
                    //if((A[0]-mid) >= temp-1) break;
                    if((A[0]-mid)*(n-i+1) + sum-S[i]<=k) high = mid-1;
                    else low = mid+1;
                }
                ans  = min(ans, high+1 + n-(i));
                //cout << ans << endl;
                //
            }
            cout << ans << endl;
            
        }
     
     
     }
     return 0;
    }
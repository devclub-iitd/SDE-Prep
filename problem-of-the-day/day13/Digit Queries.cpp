#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
using namespace std;
#define int long long
// ------------------------------------------***--------------------------------------------------
 
int pow(int i){
    if(i==0)return 1;
    return 10*pow(i-1);
}
 
vector<int>a;
int32_t main() {
    int curr = 1;
    int digit = 1;
    while(digit<=18){
        a.push_back(curr);
        curr+=9*digit*pow(digit-1);
        digit++;
    }
    int q,qq;cin>>q;
    while(q--){
        cin>>qq;
        int i = 0;
        for(i = 0;i<18;i++){
            if(a[i]>qq)break;
        }
        digit = i;
        int base = pow(digit-1);
        int offset = qq - a[digit-1];
        base+=(offset)/digit;
        offset%=digit;
        // cout<<base<<' '<<digit<<' '<<offset<<'\n';
        string num = to_string(base);
        cout<<num[offset]<<'\n';
        // if(offset==0)cout<<num[len(num)-1]<<'\n';
        // else cout<<num[offset-1]<<'\n';
    }
  return 0;
}

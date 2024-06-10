#include <bits/stdc++.h>
#define endl '\n'

typedef long long int ll;
using namespace std;

bool solve(int odd, int even, bool alice_winning, bool alice, vector<vector<vector<int>>>& memo) {
    if(odd == 0 && even == 0) {
        return alice_winning;
    }
    if(alice && memo[odd][even][alice_winning] != -1)
        return memo[odd][even][alice_winning];
    if(alice) {
        bool option1 = false, option2 = false;
        if(odd > 0)  option1 = solve(odd - 1, even, !alice_winning, false, memo);
        if(even > 0) option2 = solve(odd, even - 1, alice_winning, false, memo);
        return memo[odd][even][alice_winning] = max(option1, option2);
    } else {
        bool option1 = true, option2 = true;
        if(odd > 0)  option1 = solve(odd - 1, even, alice_winning, true, memo);
        if(even > 0) option2 = solve(odd, even - 1, alice_winning, true, memo);
        return min(option1, option2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n, el;
        cin >> n;
        int odd = 0, even = 0;
        for(int i = 0; i < n; i++) {
            cin >> el;
            odd += (abs(el) % 2 == 1);
            even += (abs(el) % 2 == 0);
        }
        vector<vector<vector<int>>> memo(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
        bool res = solve(odd, even, true, true, memo);
        cout << (res ? "Alice" : "Bob") << endl;
    }

    return 0;
}
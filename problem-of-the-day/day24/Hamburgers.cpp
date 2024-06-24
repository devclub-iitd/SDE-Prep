#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	string d; cin >> d;
	int b = 0, s = 0, c = 0;
	for(char k : d)
	{
		if(k == 'B')b++;
		else if(k == 'S')s++;
		else c++;
	}
	vector<int>h(3), p(3);
	for(int &i : h)cin >> i;
	for(int &i : p)cin >> i;
	int m; cin >> m;
	int l = 0, r = 2000000000000;
	while(l < r-1)
	{
		int mid = (l+r)/2;
		int cost = max(0ll, b*mid-h[0])*p[0]+max(0ll, s*mid-h[1])*p[1]+max(0ll, c*mid-h[2])*p[2];
		if(cost > m) r = mid;
		else l = mid;
	}
	cout << l;
}
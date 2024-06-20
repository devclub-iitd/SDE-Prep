// Let's take the first number in each array.
// Then, if we have current XOR strictly greater than zero we can output an answer.

// And if there is some array, such that it contains at least two distinct numbers, 
// you can change the first number in this array to number, that differs from it, and get XOR 0⊕x>0

// Else, each array consists of the same numbers, so all possible XORs are equal to 0 ,
// and there is no answer.

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mat[502][502];
void solve(){
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>mat[i][j];
		}
	}
	vector<int>ans(n,1);
	int temp=0;
	int a=0,b=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (mat[i][j]!=mat[i][1]){
				a=i;
				b=j;
			}
		}
		temp^=mat[i][1];
	}
	if (a==0 && temp==0){cout<<"NIE"<<'\n';}
	else{
		cout<<"TAK"<<'\n';
		if (temp==0){
			ans[a-1]=b;
		}
		for (int i=0;i<n;i++){
			cout<<ans[i]<<' ';
		}
		cout<<'\n';
	}
 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin>>t;
    t=1;
    while (t--){
      solve();
    }
}
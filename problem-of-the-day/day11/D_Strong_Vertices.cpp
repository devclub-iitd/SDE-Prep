#include <bits/stdc++.h>
using namespace std;

// The first step is to modify the inequality.

// au−av≥bu−bv⇔au−bu≥av−bv
// .

// We can create a new array c
// , where ci=ai−bi
//  and our inequality is transformed to cu≥cv
// .

// Suppose the set p1,…pm
//  is the set of such vertices v
//  that cv
//  is maximum possible. From each pi
//  there will be a path to all other vertices, because cpi
//  is not less than any other cu
// , so the set p
//  is guaranteed will be in our answer.

// Now the question is whether there are other vertices in our answer?

// Let's prove that from any such vertex v
// , that is not maximum, there is no path to any vertex from p
// . The first observation, that there is no edge between v
//  and any pi
// . So the path must go through other vertices. But even if there exist a path to another vertex u
// , cu
//  will be still less that cpi
// , so it is impossible to get any pi
// .

// In such way we proved that the answer will always be the set of such v
// , that cv
//  is maximized.

// The complexity is O(n)
// .

int main()
{
    int t ;
    cin>>t ;
    while(t--)
{
    int n ;
    cin>>n ;
    vector<pair<int,int>>v(n);
    for(int i = 0 ; i<n ; i++) {cin>>v[i].first;}
    for(int i = 0 ; i<n ; i++) {cin>>v[i].second;}
    int maxdiff = INT_MIN ;
    for(int i = 0 ; i<n ; i++)
    {
        maxdiff = max(maxdiff , v[i].first - v[i].second) ;
    }
    vector<int>ans ;
    for(int i = 0  ; i<n ; i++)
    {
        if(v[i].first - v[i].second == maxdiff)
        {
            ans.push_back(i+1);
        }
    }
    cout<<ans.size()<<endl;
    for(auto x : ans) {cout<<x<<" ";}cout<<endl;
}
}
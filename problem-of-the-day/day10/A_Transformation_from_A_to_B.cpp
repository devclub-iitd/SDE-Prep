#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Let's solve this problem in reverse way — try to get the number A from B.

// Note, that if B ends with 1 the last operation was to append the digit 1 to the right of current number. Because of that let delete last digit of B and move to the new number.

// If the last digit is even the last operation was to multiply the current number by 2. Because of that let's divide B on 2 and move to the new number.

// In the other cases (if B ends with odd digit except 1) the answer is «NO».

// We need to repeat described algorithm after we got the new number. If on some step we got the number equals to A we find the answer, and if the new number is less than A the answer is «NO».

ll solve(ll a, ll b , vector<ll>&path)
{
    if(b<a)
    {
        return -1;
    }
    if(a == b)
    {
        path.push_back(a);
        return 1;
    }
    if (b%2 == 0)
    {
        path.push_back(b);
        return solve(a,b/2 , path) ;
    }
    else
    {

        ll temp = b-1;
        if(temp%10 != 0)
        {
            return -1;
        }
        else
        {
            path.push_back(b);
            return solve(a,(b-1)/10 , path) ;
        }
        
    }
    return -1;
}


int main()
{
    ll a,b;
    cin>>a>>b;
    vector<ll>path;
    ll ans = solve(a,b,path);
    if(ans == -1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        cout<<path.size()<<endl;
        reverse(path.begin(),path.end());
        for(auto it : path)
        {
            cout<<it<<" ";
        }
    }
}
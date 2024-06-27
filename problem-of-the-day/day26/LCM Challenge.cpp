/*It is a simple problem, but many competitors used some wrong guesses and failed. First of all, we should check
if n is at most 3 and then we can simply output 1,2,6.

Now there are two cases: When n is odd, the answer is obviously n(n-1)(n-2). When n is even,
we can still get at least (n-1)(n-2)(n-3), so these three numbers in the optimal answer would not be very small compared to n.
So we can just iterate every 3 number triple in [n-50,n] and update the answer.*/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

ll lcm(ll a ,ll b){
    return a*b / (__gcd(a,b));
}

int main()
{
    long long n;
    cin >> n;
    long long ans = 0;
    if (n % 2)
    {
        ans = n * (n - 1) * (n - 2);
        if (1 == n)
            ans = 1;
    }
    else
    {
        for (long long i = max(1LL, n - 50); i <= n; i++)
            for (long long j = max(1LL, n - 50); j <= n; j++)
                for (long long k = max(1LL, n - 50); k <= n; k++)
                {
                    ans = max(ans, lcm(i, lcm(j, k)));
                }
    }
    cout << ans << "\n";
    return 0;
}
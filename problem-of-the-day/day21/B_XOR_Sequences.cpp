// Consider two numbers v
//  and u
//  such that x⊕v=y⊕u
// . Then consider the numbers x⊕(v+1) and y⊕(u+1)
// . Let's look at the last bit of v and u
// . Possible scenarios:

// Both bits are equal to 0
//  — adding one will change the bits at the same positions, therefore x⊕(v+1)=y⊕(u+1)
// 
// Both bits are equal to 1
//  — adding one will change the bits at the same positions and also add one to the next bit, therefore we can similarly consider the next bit;
// 
// Bits are different — adding one to the zero bit will only change one bit, while the subsequent bit of the other number will be changed. This means that x⊕(v+1)≠y⊕(u+1)
// .
// It is clear that we need to maximize the number of zeros in the maximum matching suffix of u and v
// . Obviously, this number is equal to the maximum matching suffix of x and y
// . Let k be the length of the maximum matching suffix of x and y
// , then the answer is 2^k
// 

// Code
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        for (int i = 0; i < 30; i++) {
            if ((a & (1 << i)) != (b & (1 << i))) {
                cout << (1ll << i) << "\n";
                break;
            }
        }
    }
}
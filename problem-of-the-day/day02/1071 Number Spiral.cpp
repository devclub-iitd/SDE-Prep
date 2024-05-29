#include <iostream> 
using namespace std;

int32_t main() {
    int t; 
    cin >> t; 
    for(int i = 0; i < t; i++) { 
        long long x, y; 
        cin >> x >> y; 
        if (y > x) {
            long long xx = y * y - y + 1; 
            long long gap = y - x; 
            // If y is odd, move to the right (increase)
            if (y % 2 == 1) {
                cout << xx + gap << '\n'; // Print the calculated position in the sequence
            } 
            // If y is even, move to the left (decrease)
            else {
                cout << xx - gap << '\n'; // Print the calculated position in the sequence
            }
        } 
        else {
            long long yy = x * x - x + 1; // Calculate the base value for the diagonal starting at (x, x)
            long long gap = x - y; // Calculate the difference between 'x' and 'y'
            
            // If x is even, move to the right (increase)
            if (x % 2 == 0) {
                cout << yy + gap << '\n'; // Print the calculated position in the sequence
            } 
            // If x is odd, move to the left (decrease)
            else {
                cout << yy - gap << '\n'; // Print the calculated position in the sequence
            }
        }
    }
    return 0;

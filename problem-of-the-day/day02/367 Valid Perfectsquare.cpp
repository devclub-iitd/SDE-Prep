class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 1, high = num;
        long long mid, ans = -1;
        while(low<=high){
            mid = low + (high-low)/2;
            if(mid*mid <=num){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return (ans*ans==num);
    }
};
class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        // We will solve this question using case analysis 
        // If k = 1, we can only rotate the string, find out the lexicographically smallest string by rotating the string
        // If k>1 it is always possible to sort the string, it can be done in following way 
        // If k>1 then we can swap any two adjacent characters in the string, so we can sort the string in ascending order (bubble sort)
        // For example, s = abcde and we want to swap c and d to achieve abdce

        // By rotating the string, bring c to the start
        // abcde -> bcdea -> cdeab 
        // Now select second index to put b at the end
        // cdeab -> ceabd 
        // Now rotate the string, and we have our characters swapped
        // ceabd -> eabdc ->  abdce

        // If k = 1, we can only rotate the string
        if(k == 1)
        {
            string ans  = s ;
            int n = s.size() ;
            s += s ;
            for(int i = 0 ; i<n ; i++)
            {
                ans = min(ans , s.substr(i,n));
            }
            return ans;
        }
        // If k > 1, we can sort the string
        else
        {
            sort(s.begin() , s.end());
            return s;
        }
        return "";
    }
};
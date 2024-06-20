class Solution {
public:
    std::vector<std::string> ans;

    void bt(int open, int close, int n, std::string& current) {
        if (open == n && close == n) {
            ans.push_back(current);
            return;
        }

        if (open < n) {
            current.push_back('(');
            bt(open + 1, close, n, current);
            current.pop_back();
        }

        if (close < open) {
            current.push_back(')');
            bt(open, close + 1, n, current);
            current.pop_back();
        }
    }

    std::vector<std::string> generateParenthesis(int n) {
        ans.clear();
        std::string current;
        bt(0, 0, n, current);
        return ans;
    }
};
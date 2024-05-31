class Solution {
public:
    bool isValid(string s) {
        // We will use stack to solve this problem
        stack<char>s1 ;

        for(int i = 0 ; i<s.size() ; i++)
        {
            // If we encounter an opening bracket, we push it to the stack
            if((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
            {
                s1.push(s[i]);
            }

            else
            {
                // If the stack is empty, we return false
                if(s1.empty()) {return false ;}
                // If we encounter a closing bracket, we check if the top of the stack is the corresponding opening bracket
                bool cond1 = s[i] == ')' && s1.top() == '(' ;
                bool cond2 = s[i] == ']' && s1.top() == '[' ;
                bool cond3 = s[i] == '}' && s1.top() == '{' ;
                if(cond1 || cond2 || cond3)
                {
                    // If it is, we pop the top of the stack
                    s1.pop();
                }
                else
                {
                    // If it is not, we return false
                    return false ;
                }
            }
        }    
        // If the stack is empty, then the string is valid
        return s1.empty();
    }
};
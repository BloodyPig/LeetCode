Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true


// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
// Memory Usage: 8.9 MB, less than 79.95% of C++ online submissions for Valid Parentheses.

class Solution {
public:
    
    bool cmp(char c1,char c2){
        if(c1=='('&&c2==')')
            return true;
        else if(c1=='{'&&c2=='}')
            return true;
        else if(c1=='['&&c2==']')
            return true;
        else 
            return false;
    }
    
    bool isValid(string s) {
        stack<char> ss;
        
        for(int i=0;i<s.size();i++){
            if(ss.empty())
                ss.push(s[i]);
            else{
                if(cmp(ss.top(),s[i]))
                    ss.pop();
                else
                    ss.push(s[i]);
            }
        }
        return ss.empty();
    }
};
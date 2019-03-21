Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?


// Runtime: 112 ms, faster than 87.98% of C++ online submissions for Palindrome Number.
// Memory Usage: 73.2 MB, less than 17.18% of C++ online submissions for Palindrome Number.

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        string s = to_string(x);
        for(int i=0;i<s.length()/2;i++){
            if(s[i]!=s[s.length()-1-i])
                return false;
        }
        return true;
    }
};

// Runtime: 116 ms, faster than 77.11% of C++ online submissions for Palindrome Number.
// Memory Usage: 72.9 MB, less than 91.02% of C++ online submissions for Palindrome Number.

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 ||(x%10==0 && x!=0))return false;
         int sum=0;
        while(x>sum){
            sum = sum*10 + x%10;
            x /= 10;
        }
        return x==sum || x==sum/10;
    }
};
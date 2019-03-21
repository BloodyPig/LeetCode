Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: 
[−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.


// Runtime: 12 ms, faster than 98.20% of C++ online submissions for Reverse Integer.
// Memory Usage: 14.1 MB, less than 16.19% of C++ online submissions for Reverse Integer.

class Solution {
public:
    int reverse(int x) {
        int sum=0;
        while(x!=0){
            if(sum >INT_MAX/10||(sum==INT_MAX/10&& x%10>7))
                return 0;
            if(sum < INT_MIN/10||(sum==INT_MIN/10&& x%10<-8))
                return 0;
            sum = sum*10 + x%10;
            x /= 10;
        }
        return sum;
    }
};
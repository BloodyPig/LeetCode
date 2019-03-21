Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

// Runtime: 8 ms, faster than 98.92% of C++ online submissions for Implement strStr().
// Memory Usage: 9.5 MB, less than 44.27% of C++ online submissions for Implement strStr().

//一行解决 但是这不是问题本意

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};
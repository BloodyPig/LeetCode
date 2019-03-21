Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.

// Runtime: 8 ms, faster than 99.30% of C++ online submissions for Longest Common Prefix.
// Memory Usage: 9.6 MB, less than 35.47% of C++ online submissions for Longest Common Prefix.

class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";
        if (strs.size() == 1)
            return strs[0];
        sort(strs.begin(), strs.end());
        int len = 0;
        bool flag;
        while (len <= strs[0].size())
        {
            flag = true;
            for (int i = 0; i < strs.size(); i++)
            {
                if (strs[i][len] != strs[0][len])
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
            len++;
        }
        return strs[0].substr(0, len);
    }
};
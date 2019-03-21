Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

// Runtime: 56 ms, faster than 23.54% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 21.5 MB, less than 13.60% of C++ online submissions for Longest Substring Without Repeating Characters.

//滑动窗口 用集合判断接下来的元素是否重复

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0||s.size()==1)return s.size();
        int n = s.size();
        set<char> ss;
        int ans = 0, i =0,j=0;
        while(i<n&&j<n){
            if(ss.count(s[j])==0){
                ss.insert(s[j++]);
                ans = max(ans,j-i);
            }
            else
                ss.erase(s[i++]);
        }
        return ans;
    }
};

// Runtime: 20 ms, faster than 97.63% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 16.1 MB, less than 60.52% of C++ online submissions for Longest Substring Without Repeating Characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(256,-1);
        int len = 0,start = -1;
        for(int i=0;i<s.size();i++){
            if(v[s[i]]>start)
                start = v[s[i]];
            v[s[i]] = i;
            len = max(len,i-start);
        }
        return  len;
    }
};
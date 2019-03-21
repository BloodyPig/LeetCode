Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

// v1
// Runtime: 16 ms, faster than 58.54% of C++ online submissions for Two Sum.
// Memory Usage: 10.8 MB, less than 5.02% of C++ online submissions for Two Sum.

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.count(nums[i]) != 0)
            {
                v.push_back(m.at(nums[i]));
                v.push_back(i);
            }
            m.insert(pair<int, int>(target - nums[i], i));
        }
        return v;
    }
};

//V2
// Runtime: 12 ms, faster than 95.04% of C++ online submissions for Two Sum.
// Memory Usage: 10.3 MB, less than 40.12% of C++ online submissions for Two Sum.

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.count(nums[i]) != 0)
                return std::vector{m.at(nums[i]), i};
            m.insert(pair<int, int>(target - nums[i], i));
        }
        return {0};
    }
};
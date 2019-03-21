Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0

// Runtime: 8 ms, faster than 99.04% of C++ online submissions for Search Insert Position.
// Memory Usage: 9.3 MB, less than 37.98% of C++ online submissions for Search Insert Position.

//线性查找

class Solution
{
  public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (target < nums[0])
            return 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= target)
                return i;
        }
        return nums.size();
    }
};

// Runtime: 12 ms, faster than 15.40% of C++ online submissions for Search Insert Position.
// Memory Usage: 9.2 MB, less than 63.70% of C++ online submissions for Search Insert Position.

//这个二分查找实际效率很低 因为总要把整个数组遍历一边
class Solution
{
  public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (target < nums[0])
            return 0;
        int low = 0, high = nums.size() - 1, mid = low + (high - low) > 1;
        while (high >= low)
        {
            mid = low + (high - low) / 2;
            if (target > nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};
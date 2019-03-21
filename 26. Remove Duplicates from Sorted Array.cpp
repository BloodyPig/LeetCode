Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.
Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}



//意思是求出数组元素构成的集合大小n 同时使得数组的前n个元素就是这个集合

// Runtime: 24 ms, faster than 99.52% of C++ online submissions for Remove Duplicates from Sorted Array.
// Memory Usage: 10.9 MB, less than 59.69% of C++ online submissions for Remove Duplicates from Sorted Array.

//Unique将排序后的重复元素放在最后 并且返回对应位置 erase将这些元素删除
//不是问题本身

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};


// untime: 24 ms, faster than 99.52% of C++ online submissions for Remove Duplicates from Sorted Array.
// Memory Usage: 11 MB, less than 17.94% of C++ online submissions for Remove Duplicates from Sorted Array.

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int cnt = 0;
    for (int i = 1; i < nums.size(); i++)
    {
      if (nums[i] == nums[i - 1])
        cnt++;
      else
        nums[i - cnt] = nums[i];
    }
    return nums.size() - cnt;
  }
};

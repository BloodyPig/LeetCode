Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: 
[−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.

// Runtime: 12 ms, faster than 98.84% of C++ online submissions for Divide Two Integers.
// Memory Usage: 13.9 MB, less than 7.16% of C++ online submissions for Divide Two Integers.

// 题目规定不可以使用乘除模 为了速度使用位运算
// 这个答案的想法是这样 对于任意除法都是加减法 加减法的次数决定了程序的执行效率
// 每个答案都可以在最开始时候加上一个2的整数次幂 
// 比如100/3 可以初始化答案为32 100/10可以初始化答案为8 极大减少了加减法次数

class Solution
{
  public:
    int divide(int dividend, int divisor)
    {
        if (divisor == 1)
            return dividend;
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        long dvd = abs((long)dividend), delta = abs((long)divisor), tims = 1, ans = 0;
        while (dvd >= delta)
        {
            tims <<= 1;
            delta <<= 1; //delta=tims*divisor
        }
        while (dvd > 0 && delta > 0)
        {
            while (dvd < delta)
            {
                tims >>= 1;
                delta >>= 1;
            }
            ans += tims;
            dvd -= delta;
        }
        return (dividend > 0) ^ (divisor > 0) ? -ans : ans; //XOR^
    }
};
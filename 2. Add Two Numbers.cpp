You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

// Runtime: 40 ms, faster than 96.58% of C++ online submissions for Add Two Numbers.
// Memory Usage: 19.1 MB, less than 66.73% of C++ online submissions for Add Two Numbers.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        int sum=0;
        ListNode Head(0),*p = &Head;
        int rest = 0;
        while(l1!=NULL || l2!=NULL || rest){
            sum =0;
            sum = (l1?l1->val:0)+(l2?l2->val:0)+rest;
            rest = sum/10;
            p->next = new ListNode(sum%10);
            p=p->next;
            l1 = l1?l1->next:l1;
            l2 = l2?l2->next:l2;
        }
       return Head.next;
    }
};
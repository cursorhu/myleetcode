83. 删除排序链表中的重复元素.cpp
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:
输入: 1->1->2
输出: 1->2


/*
题解：
注意题目是排序的链表，重复元素一定连续
双指针法，一快一慢，快指针不断右移跳过重复，慢指针仅当值不同时更新到快指针
注意没有free节点，有内存泄漏
*/


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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) 
        	return nullptr;
	    
	    ListNode *slow = head, *fast = head;
	    while (fast != nullptr) {
	    	//当值不相等，slow要跟随fast
	    	//当值相等，slow没动，仅fast移动，直到下一次值不相等，即跳过了重复的节点。
	        if (fast->val != slow->val) {
	            slow->next = fast;
	            slow = slow->next;
	        }
	        fast = fast->next; //注意这个fast更新放在if后面，为了尾节点的边界情况
	    }
	    //跳过尾部重复节点
	    slow->next = nullptr;
	    return head;
	}
};
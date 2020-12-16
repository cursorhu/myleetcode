/*206. 反转链表

反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
*/


/*
题解：双指针保留当前节点前后的节点, 每轮从右到左更新next,head,prev，最后更新head进入下一轮
流程：
	0.初始化双指针prev,next，用于当前节点head的左右节点指针
	while(head != NULL)
	1.保存右侧位置：更新右节点next为head->next
	2.当前节点逆向：head指向prev，此时链表断开
	3.更新prev，保存断开位置，即head
	4.更新head位置为next，为下一轮翻转做准备
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
    ListNode* reverseList(ListNode* head) {
    	ListNode *prev = nullptr, 
    	ListNode *next;
		while (head) {
			next = head->next;
			head->next = prev;
			prev = head;
			head = next;
		}
		return prev;
};

234. 回文链表.cpp
请判断一个链表是否为回文链表。

示例:
输入: 1->2->2->1
输出: true

/*
题解：
先使用快慢指针找到链表中点，再把链表切成两半；
然后把后半段翻转；最后同速度遍历，比较两半是否相等
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
    bool isPalindrome(ListNode* head) {
    	if(!head || !head->next)
    		return true;
    	ListNode *slow = head, *fast = head;
    	while(fast->next && fast->next->next) //注意这个判断条件,不分链表奇偶
    	{
    		slow = slow->next;	//一倍速移动
    		fast = fast->next->next; //两倍速移动
    	}
    	//不论链表是奇数还是偶数，翻转的都是右边一半的链表
    	//比较前要右移到右边一半链表的首节点
    	slow->next = reverseList(slow->next);
    	slow = slow->next;
    	while(slow)
    	{
    		if(head->val != slow->val)
    			return false;
    		head = head->next; //同速遍历
    		slow = slow->next;
    	}
    	return true;
    }

    //题目206.翻转链表
    ListNode* reverseList(ListNode* head) {
    	ListNode *prev = nullptr; 
    	ListNode *next;
		while (head) {
			next = head->next;
			head->next = prev;
			prev = head;
			head = next;
		}
		return prev;
	}
};
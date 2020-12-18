148. 排序链表.cpp
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

进阶：
你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？

输入：head = [4,2,1,3]
输出：[1,2,3,4]


/*
常见排序方法有很多，插入排序，选择排序，堆排序，快速排序，冒泡排序，归并排序，桶排序
O(nlgn)，符合要求只有快速排序，归并排序，堆排序
链表排序，最适合用归并排序
用快排，不能根据下标访问节点，堆排序适用于能新建结点的情景，不适用交换节点
归并 = 二分 + 递归的合并排序
二分用快慢指针，有序的合并排序在题目(21. 合并两个有序链表）已经实现
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
    	if(!head || !head->next)
    		return head;
    	ListNode *slow = head, *fast = head;
    	ListNode *headA, *headB;
    	while(fast->next && fast->next->next)
    	{
    		slow = slow->next;	//一倍速移动
    		fast = fast->next->next; //两倍速移动
    	}
    	//此时slow为中点，此处断开链表
    	headA = head;
    	headB = slow->next;
    	slow->next = nullptr;

    	//递归合并排序，子链表在递归函数不断拆成两半，当拆到链表只有一个结点时，递归逐层返回有序子链表、
    	//递归的逻辑类似“信用贷款”，已知sortList返回的是有序链表，所以mergeTwoLists可以处理
    	//求解sortList，不断二分且阻塞在return, 直到二分到单节点，开始“还贷款”，函数堆栈层层返回有序链表，每层的mergeTwoLists真正执行
    	//最终返回有序的原链表
    	return mergeTwoLists(sortList(headA), sortList(headB));
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *node = dummy;

        while(l1 && l2) //先按序取完一个链表再说
        {
        	if(l1->val < l2->val)
        	{
        		node->next = l1; //按小值取节点
        		l1 = l1->next; //更新被取链表
        	}
        	else
        	{
        		node->next = l2;
        		l2 = l2->next;
        	}
        	node = node->next; //更新目标
        }

        //值较小的链表已经取完了，另一个值都较大，且已排序，直接链接上去
        node->next = l1 ? l1 : l2; //l1不为空则l2是剩余的链表，取l1，否则l2
        //返回头节点指针
        return dummy->next;
    }

};
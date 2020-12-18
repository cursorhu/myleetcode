328. 奇偶链表.cpp
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。
请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

示例 1:

输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL

/*
题解：
双指针分别奇偶遍历，最后把两个链表链接，返回头指针
画图分析链表为奇数和偶数情况，注意判断条件
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
    ListNode* oddEvenList(ListNode* head) {
    	if(!head)
    		return nullptr;
        
        ListNode *headOdd = head, *headEven = head->next; //保存奇偶链表头
        ListNode *pOdd = headOdd, *pEven = headEven; //用于遍历
        //结束条件要画图分析奇偶，是否有漏节点
        while(pOdd && pOdd->next && pEven && pEven->next)
        {
        	pOdd->next = pEven->next; //跳节点链接
        	pOdd = pOdd->next; //更新位置
        	pEven->next = pOdd->next;
        	pEven = pEven->next;
        }

        pOdd->next = headEven; //链接子链表

        return headOdd;
    }
};
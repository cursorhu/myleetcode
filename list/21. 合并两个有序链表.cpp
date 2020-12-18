
/*
21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

/*
题解：
	1.把“合并”理解成“创建新链表”
	2.先创建虚拟节点 (dummy node)，便于处理增删操作
	3.循环内遍历两个链表，任一个链表遍历完就结束
	4.每次遍历，比较两个链表的当前节点值
	5.新链表节点指向较小的那个，达到“选中”效果
	6.然后更新被选中链表，和新链表的节点位置
	7.最终有一个链表被先“取完”，循环结束
	8.剩下的链表的值一定大于新链表，且已经有序，直接链接过去完成合并

事实上，本题实现两个链表的归并排序，即使输入是无序链表，合并后也是有序链表

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
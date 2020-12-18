19. 删除链表的倒数第N个节点.cpp
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：
给定一个链表: 1->2->3->4->5, 和 n = 2.
当删除了倒数第二个节点后，链表变为 1->2->3->5.



/*
题解：
有两个思路：
1.链表没法反向遍历，可以先翻转链表，找到节点删掉，再翻转回来
2.考虑双指针找链表中点的方式（234.回文链表），两个指针按某种规则移动，根据其中一个指针的位置，能定位另一个指针的位置
找中点是快指针按2倍速，慢指针1倍速，当快指针到链表尾（nullptr），慢指针一定在中点（分奇偶）
本题也可用双指针，当快指针到尾部，慢指针在倒数第n个节点
倒推出规则：两个指针固定间隔，形成滑动窗口，同速度遍历。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //注意边界要考虑只有一个节点的情况
        if(!head || !head->next) 
        	return nullptr;
        //新建虚拟节点指向head,在删除节点题目中常用
        //如果slow直接指向head,那么最终被删除的节点就是slow，找不到其左边的节点
        //dummy作用是保存删除节点左侧节点的位置：最终slow->next才是要删除的节点，slow链接到slow->next->next
        ListNode *dummy = new ListNode();
        dummy->next = head;
        
        ListNode *fast = head, *slow = dummy;
        ListNode *newhead = head; //头结点可能变化，例如删除的正好是头节点

        //初始化fast到位置n
        for(int i = 0; i < n; ++i)
        {
        	if(!fast) //链表节点数不足n
        		return head;
        	fast = fast->next;
        }

        while(fast) //右移窗口，直到fast到尾部
        {
        	fast = fast->next;
        	slow = slow->next;
        }

        //slow为要删除的节点左侧位置
        //leetcode不要求释放节点, 实际开发需要释放
        ListNode *tmp = slow->next; //先保存要删除节点位置
        if(tmp == head) //删除的是头结点
        	newhead = head->next;
        slow->next = slow->next->next; //从链表逻辑连接上删除
        delete tmp; //从内存上释放节点

        return newhead;
    }
};
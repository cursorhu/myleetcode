/*
160. 相交链表
编写一个程序，找到两个单链表相交的起始节点。
如果两个链表没有交点，返回 null
*/

/*
双指针跑两个链表，图解参考：
https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/tu-jie-xiang-jiao-lian-biao-by-user7208t/
*/

class Solution {
public:
    //题解：设链表A的长度为a+c，链表B的长度为b+c，a为链表A不公共部分，b为链表B不公共部分，c为链表A、B的公共部分
    //将两个链表连起来，A->B和B->A，长度：a+c+b+c=b+c+a+c，若链表AB相交，则a+c+b与b+c+a就会抵消，它们就会在c处相遇；
    //若不相交，则c为nullptr，则a+b=b+a，它们各自移动到尾部循环结束，即返回nullptr
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(!headA||!headB)
        	return nullptr;
        
        ListNode *pA=headA,*pB=headB;
        //相交情况，交叉后会存在pA == pB != NULL的时刻，此时退出循环
        //不相交等长情况，会同时NULL, 退出循环
        //不相交不等长情况，交叉指向后最终也会同时NULL,退出循环
        while(pA!=pB){ 
            //当pA或pB为空时，重新指向另一链表的头部
            pA=pA?pA->next:headB;
            pB=pB?pB->next:headA;
        }
        return pA;
    }    
};
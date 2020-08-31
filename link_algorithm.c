#include <stdio.h>
#include <string.h>


 struct ListNode {
      int val;
     struct ListNode *next;
  };
// 返回链表倒数第k个节点
int kthToLast(struct ListNode* head, int k){
    int i=0;
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while(fast->next != NULL)
    {
        fast = fast->next;
        i++;
        if(i>=k)
            slow=slow->next;
    }
    return slow->val;
}


// 双指针反转链表
struct ListNode* reverseList(struct ListNode* head){
    //双指针法
    if(head==NULL||head->next==NULL)return head;
    struct ListNode *p=NULL,*q=head,*temp=NULL;
    while(q!=NULL){
        temp=q->next;
        q->next=p;
        p=q;
        q=temp;
    }
    return p;
}


// 判断链表是否有环
//bool hasCycle(struct ListNode *head) {
//    if(head == NULL || head->next == NULL) return false;
//    struct ListNode *fast = head;
//    struct ListNode *slow = head;
//    while(slow && fast && fast->next){
//        fast = fast->next->next;
//        slow = slow->next;
//        if(fast == slow){
//            return true;
//        }
//    }
//    return false;
//}

// 返回两个单链表的交点，假设两个链表均无环
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p = headA;
    struct ListNode *q = headB;
    while(p != q){
        p = p == NULL ? headB : p->next;
        q = q == NULL ? headA : q->next;
    }
    return p;
}




int main(){


	return 0;
}




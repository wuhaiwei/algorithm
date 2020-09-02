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


//合并两个有序链表
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(!l1) return l2;
    if(!l2) return l1;
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode)), *t = head;
    while(l1 && l2){
        if(l1->val <= l2->val){
            t->next = l1;
            l1 = l1->next;
        }else{
            t->next = l2;
            l2 = l2->next;
        }
        t = t->next;
    }
    if(l1) t->next = l1;
    else if(l2) t->next = l2;
    return head->next;
}


//递归法合并两个有序链表
struct ListNode* mergeTwoListsByRecursion(struct ListNode* l1, struct ListNode* l2){
    if(!l1) return l2;
    if(!l2) return l1;
    if(l1->val <= l2->val){
        l1->next = mergeTwoListsByRecursion(l1->next,l2);
        return l1;
    }else{
        l2->next = mergeTwoListsByRecursion(l1,l2->next);
        return l2;
    }
}


int main(){


	return 0;
}




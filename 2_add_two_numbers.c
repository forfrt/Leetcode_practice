#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

int main(int argc, char **argv) {
    struct ListNode *lia=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode lib;

    lia->val=2;
    lia->next=(struct ListNode*)malloc(sizeof(struct ListNode));
    lia->next->val=4;
    lia->next->next=(struct ListNode*)malloc(sizeof(struct ListNode));
    lia->next->next->val=3;

    lib.val=5;
    lib.next=(struct ListNode*)malloc(sizeof(struct ListNode));
    lib.next->val=6;
    lib.next->next=(struct ListNode*)malloc(sizeof(struct ListNode));
    lib.next->next->val=4;

    struct ListNode *res=addTwoNumbers(lia, &lib);

    while(res->next!=NULL) {
        printf("%d\n", res->val);
        printf("%p\n", res->next);
        fflush(stdout);
        res=res->next;
    }


}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *res= malloc(sizeof(struct ListNode));
    res->next=NULL;
    struct ListNode *tmp=res;

    int flag;

    while(l1 || l2 || flag) {

        int x=0, y=0;

        if(l1) {
            x=l1->val;
            l1=l1->next;
        }

        if(l2) {
            y=l2->val;
            l2=l2->next;
        }

        flag=answer>9;

        tmp=tmp->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val=answer%10;
        int answer=x+y+flag;
        tmp->next=NULL;
    }

    return res->next;
}

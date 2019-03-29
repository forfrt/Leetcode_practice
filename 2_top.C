
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
    public:
        static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
            ListNode preHead(0), *p=&preHead;
            int extra=0;
            while(l1||l2||extra){
                int sum=(l1?l1->val:0)+(l2?l2->val:0)+extra;
                extra=sum/10;
                p->next=new ListNode(sum%10);
                p=p->next;
                l1=l1?l1->next:l1;
                l2=l2?l2->next:l2;

            }
            return preHead.next;
        }
};

int main(int argc, char **argv){
    struct ListNode *lia=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *lib=(struct ListNode*)malloc(sizeof(struct ListNode));

    lia->val=2;
    lia->next=(struct ListNode*)malloc(sizeof(struct ListNode));
    lia->next->val=4;
    lia->next->next=(struct ListNode*)malloc(sizeof(struct ListNode));
    lia->next->next->val=3;
    
    lib->val=5;
    lib->next=(struct ListNode*)malloc(sizeof(struct ListNode));
    lib->next->val=6;
    lib->next->next=(struct ListNode*)malloc(sizeof(struct ListNode));
    lib->next->next->val=4;

    struct ListNode *res=Solution::addTwoNumbers(lia, lib);

    while(res){
        printf("%d\n", res->val);
        res=res->next;
    }
    
}


#include "headers/CoreMinial.h"
#include "headers/UStruct.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) { return l2; }
        if (!l2) { return l1; }
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                head->next = new ListNode(l2->val);
                l2 = l2->next;
            } else {
                head->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            head = head->next;
        }
        if (l1) {
            head->next = l1;
        }
        if (l2) {
            head->next = l2;
        }
        return res->next;
    }
};
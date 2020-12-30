#include "headers/CoreMinial.h"
#include "headers/UStruct.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* preHead = new ListNode(-1);
        preHead->next = head;
        ListNode* temp = nullptr;
        ListNode* copyHead = preHead;
        while (copyHead->next && copyHead->next->next) {
            temp = copyHead->next->next;
            copyHead->next->next = temp->next;
            temp->next = copyHead->next;
            copyHead->next = temp;
            copyHead = copyHead->next->next;
        }
        return preHead->next;
    }
};
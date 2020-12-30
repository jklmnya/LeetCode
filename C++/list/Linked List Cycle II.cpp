#include "headers/CoreMinial.h"
#include "headers/UStruct.h"

/**
 * 
 *      Two pointer
 *      fast pointer and slow pointer  -> judge if the list has a circle
 **/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) { break; }
        }
        if (!fast || !fast->next) { return nullptr; }
        // get the answer
        slow = fast;
        while (slow != head) {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};
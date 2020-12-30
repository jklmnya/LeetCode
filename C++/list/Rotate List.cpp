#include "headers/CoreMinial.h"
#include "headers/UStruct.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) { return head; }
        int size = 0;
        stack<ListNode*> s;
        ListNode* node = head;
        while (node) {
            size++;
            s.push(node);
            node = node->next;
        }
        k = k % size;
        if (k != 0) {
            node = s.top();
            for (int i = 0;i<k;i++) {
                head = s.top();
                s.pop();
            }
            s.top()->next = nullptr;
            // find the last ListNode* in stack
            ListNode* last = nullptr;
            while (!s.empty())  {
                last = s.top();
                s.pop();
            }
            node->next = last;
            return head;
        } else {
            return head;
        }
    }
};
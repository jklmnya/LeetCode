#include "headers/CoreMinial.h"
#include "headers/UStruct.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> m;
        ListNode* node = head;
        while (node) {
            m[node->val]++;
            node = node->next;
        }
        node = new ListNode(-101);
        ListNode* res = node;
        for (auto& p : m) {
            if (p.second == 1) {
                node->next = new ListNode(p.first);
                node = node->next;
            }
        }
        return res->next;
    }
};
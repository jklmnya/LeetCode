#include "headers/CoreMinial.h"
#include "headers/UStruct.h"

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root) { return true; }
        queue<TreeNode*> q;
        int size = 1;
        int level = 1;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = nullptr;
            if (level % 2 == 1) {
                int start = INT_MIN;
                for (int i = 0;i<size;i++) {
                    node = q.front();
                    q.pop();
                    if (node->val % 2 == 0 || node->val <= start) { return false; }
                    start = node->val;
                    if (node->left) { q.push(node->left); }
                    if (node->right) { q.push(node->right); }
                }
            } else {
                int start = INT_MAX;
                for (int i = 0;i<size;i++) {
                    node = q.front();
                    q.pop();
                    if (node->val % 2 == 1 || node->val >= start) { return false; }
                    start = node->val;
                    if (node->left) { q.push(node->left); }
                    if (node->right) { q.push(node->right); }
                }
            }
            size = q.size();
            level++;
        }
        return true;
    }
};
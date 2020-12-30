#include "headers/UStruct.h"
#include "headers/CoreMinial.h"

class Solution {
public:
    
    int res = 0;
    
    int maxAncestorDiff(TreeNode* root) {
        if (root) {
            getMaxDiff(root, root->val, root->val);
        }
        return res;
    }
    
    void getMaxDiff(TreeNode* node, int maxValue, int minValue) {
        if (node) {
            res = max(res, max(abs(maxValue - node->val), abs(minValue - node->val)));
            maxValue = max(maxValue, node->val);
            minValue = min(minValue, node->val);
            getMaxDiff(node->left, maxValue, minValue);
            getMaxDiff(node->right, maxValue, minValue);
        }
        
    }
};
#include "headers/CoreMinial.h"
#include "headers/UStruct.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root) {
            return (abs(getHeight(root->left) - getHeight(root->right)) <= 1) 
                    && isBalanced(root->left) && isBalanced(root->right) ? true : false;
        } else { return true; }
    }
    
    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
};
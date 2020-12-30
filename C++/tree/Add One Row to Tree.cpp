#include "headers/CoreMinial.h"
#include "headers/UStruct.h"

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        TreeNode* res = root;
        if (d == 1) { 
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }
        addRow(root, 2, v, d);
        return res;
    }
    
    void addRow(TreeNode* node, int level, int v, int d) {
        if (node) {
            if (level == d) {
                TreeNode* leftChild = new TreeNode(v);
                TreeNode* rightChild = new TreeNode(v);
                leftChild->left = node->left;
                rightChild->right = node->right;
                node->left = leftChild;
                node->right = rightChild;
                return;
            } else {
                addRow(node->left, level + 1, v, d);
                addRow(node->right, level + 1, v, d);
            }
        }
    }
};
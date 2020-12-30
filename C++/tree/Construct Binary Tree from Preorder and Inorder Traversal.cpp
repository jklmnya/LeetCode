#include "headers/CoreMinial.h"
#include "headers/UStruct.h"

class Solution {
    
public:
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pLeft, int pRight, int iLeft, int iRight) {
        if (pLeft > pRight || iLeft > iRight) { return nullptr; }
        TreeNode* node = new TreeNode(preorder[pLeft]);
        int i = iLeft;
        for (;i<inorder.size();i++) {
            if (inorder[i] == node->val) {
                break;
            }
        }
        node->left = buildTree(preorder, inorder, pLeft + 1, pLeft + i - iLeft, iLeft, i - 1);
        node->right = buildTree(preorder, inorder, pLeft + i - iLeft + 1, pRight, i + 1, iRight);
        return node;
    }
};
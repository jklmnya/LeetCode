#include "headers/CoreMinial.h"
#include "headers/UStruct.h"

/*
    inorder = [9,3,15,20,7]
    postorder = [9,15,7,20,3]

    3
   / \
  9  20
    /  \
   15   7

    iLeft, iRigth --> range of inorder
    pLeft, pRight --> range of postorder

    every interation 

    0. judge (iLeft > iRight || pLeft > pRight) 
    1. Construct the TreeNode which val is postorder[pRight]
    2. find the value in inorder which is equals node->val and get the index i
    3. update iLeft, iRight, pLeft, pRight
    4. node->left : inorder range = [iLeft, i - 1], postorder range = [pLeft, pLeft + i - iLeft - 1]
       node->right : inorder range = [i + 1, iRight], postorder range = [pLeft + i - iLeft, pRight - 1]
    
*/

class Solution {
public:
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int iLeft, int iRight, int pLeft, int pRight) {
        if (iLeft > iRight || pLeft > pRight) { return nullptr; }
        TreeNode* node = new TreeNode(postorder[pRight]);
        int i = iLeft;
        for (;i<inorder.size();i++) {
            if (inorder[i] == node->val) {
                break;
            }
        }
        node->left = buildTree(inorder, postorder, iLeft, i - 1, pLeft, pLeft + i - iLeft - 1);
        node->right = buildTree(inorder, postorder, i + 1, iRight, pLeft + i - iLeft, pRight - 1);
        return node;
    }
};
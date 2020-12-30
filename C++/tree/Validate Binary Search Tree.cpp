#include "headers/CoreMinial.h"
#include "headers/UStruct.h"

class Solution {
public:
    
    long val = LONG_MIN;
    
    bool isValidBST(TreeNode* root) {
        if (root) {
            if (!isValidBST(root->left)) { return false; }
            if ((long)root->val <= val) { 
                return false; 
            }
            else { 
                val = (long)root->val;
                return isValidBST(root->right); 
            }
        }
        return true;
    }
    
};
#include "headers/CoreMinial.h"
#include "headers/UStruct.h"

class Solution {
public:
    string tree2str(TreeNode* t) {
        string res = "";
        if (t) {
           getString(t, res);
            res.erase(0, 1);
            res.erase(res.size() - 1, 1);
        }
        return res;
    }
    
    void getString(TreeNode* node, string& str) {
        if (node) {
            str += "(";
            str += to_string(node->val);
            if (!node->left && node->right) {
                str += "()";
            }
            getString(node->left, str);
            getString(node->right, str);
            str += ")";
        }
    }
    
};
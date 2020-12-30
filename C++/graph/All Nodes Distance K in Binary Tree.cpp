#include "headers/CoreMinial.h"
#include "headers/UStruct.h"

class Solution {
public:
    
    int start = -1;
    int tK;
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<vector<int>> graph(501, vector<int>(501, 0));
        vector<int> res;
        createGraph(root, graph);
        if (target) { start = target->val; } 
        else { return res; }
        tK = K;
        bfs(start, 0, res, graph);
        return res;
    }
    
    void createGraph(TreeNode* node, vector<vector<int>>& graph) {
        if (node) {
            if (node->left) {
                graph[node->val][node->left->val] = 1;
                graph[node->left->val][node->val] = 1;
            }
            if (node->right) {
                graph[node->val][node->right->val] = 1;
                graph[node->right->val][node->val] = 1;
            }
            createGraph(node->left, graph);
            createGraph(node->right, graph);
        }
    }
    
    void bfs(int curr, int dis, vector<int>& res, vector<vector<int>>& graph) {
        if (dis == tK) {
            res.push_back(curr);
            return;
        }
        for (int i = 0;i<501;i++) {
            if (graph[curr][i] == 1) {
                graph[curr][i] = 0;
                graph[i][curr] = 0;
                bfs(i, dis + 1, res, graph);
            }
        }
    }
    
};
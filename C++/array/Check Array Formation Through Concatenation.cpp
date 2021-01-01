#include "headers/CoreMinial.h"

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int, int> m;
        for (int i = 0;i<arr.size();i++) { m[arr[i]] = i; }
        for (auto& piece : pieces) {
            if (piece.size() == 1) {
                if (m.find(piece[0]) == m.end()) {
                    return false;
                }
            } else {
                int start = m[piece[0]] - 1;
                for (auto& p : piece) {
                    if (m.find(p) == m.end() || ++start != m[p]) {
                        return false;
                    }
                }   
            }
        }
        return true;
    }
};
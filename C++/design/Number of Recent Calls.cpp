#include "headers/CoreMinial.h"

class RecentCounter {
public:
    
    int minValue = INT_MIN;
    int minIndex = 0;
    int res = 0;
    vector<int> vec;
    
    RecentCounter() {
        
    }
    
    int ping(int t) {
        vec.push_back(t);
        int minV = t - 3000;
        if (minV > minValue) {
            for (int i = minIndex;i<vec.size();i++) {
                if (vec[i] >= minV) {
                    minIndex = i;
                    minV = vec[i];
                    break;
                } else {
                    res--;
                }
            }
        }
        res++;
        return res;
    }
};

